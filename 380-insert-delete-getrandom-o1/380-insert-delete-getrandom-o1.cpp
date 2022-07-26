class RandomizedSet {
public:
    vector<int>num;
    unordered_map<int,int>index;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(index.find(val)!=index.end())return false;
        num.push_back(val);
        index[val] = num.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(index.find(val)==index.end())return false;
        int last = num.back();
        num[index[val]] = last;
        num.pop_back();
        index[last] = index[val];
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        return num[rand()%num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */