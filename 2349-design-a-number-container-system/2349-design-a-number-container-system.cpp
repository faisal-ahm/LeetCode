class NumberContainers {
public:
    unordered_map<int,int> indexNum;
    unordered_map<int,set<int>>numIndex;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexNum.find(index) == indexNum.end()){
            indexNum[index] = number;
            numIndex[number].insert(index);
            return;
        }
        int old = indexNum[index];
        indexNum[index] = number;
        numIndex[old].erase(index);
        numIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numIndex[number].size() == 0) return -1;
        return *numIndex[number].begin();
    }
};

