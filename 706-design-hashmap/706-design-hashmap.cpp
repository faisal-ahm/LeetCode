class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    const static int size = 19997;
    const static int mult = 12582917;
    
    MyHashMap(){
        m.resize(size);
    }
    
    int hash(int key){
        return (int)((long)key * mult % size);
    }
    
    list<pair<int,int>> :: iterator search(int key){

        int i = hash(key);
        auto it = m[i].begin();
        while(it!=m[i].end()){
            if(it->first == key) break;
            ++it;
        }
        return it;
    }
    
    bool contains(int key){
        int index = hash(key);
        return m[index].end() != search(key);
    }
    
    void put(int key, int value) {
        int i = hash(key);
        if(contains(key)){
            search(key)->second = value;
            return;
        }
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        if(!contains(key)) return -1;
        return search(key)->second;
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        m[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */