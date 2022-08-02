class LRUCache {
public:
    unordered_map<int,int> m;
    unordered_map<int, list<int> :: iterator> address;
    list<int> l;
    int cap;
    int size;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        list<int> :: iterator it = address[key];
        l.erase(it); //erasing key from the list
        address.erase(key); //erasing address from the address map
        l.push_front(key);//adding key to the front of the list
        address[key] = l.begin();//updating address with new node address which is infront
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            l.erase(address[key]);
            address.erase(key);
            m.erase(key);
            size--;
        }
        if(size == cap){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        size++;
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */