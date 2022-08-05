class CustomStack {
public:
    int size;
    int mSize;
    vector<int>v;
    CustomStack(int maxSize) {
        mSize = maxSize;
        size = 0;
        v = vector<int>(maxSize);
    }
    
    void push(int x) {
        if(size >= mSize) return;
        v[size++] = x;
    }
    
    int pop() {
        if(size <= 0) return -1;
        size--;
        return v[size];
    }
    
    void increment(int k, int val) {
        int i = 0;
        while(i < k && i < size){
            v[i] += val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */