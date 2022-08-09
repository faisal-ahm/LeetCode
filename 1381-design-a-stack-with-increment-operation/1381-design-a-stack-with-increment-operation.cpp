class CustomStack {
public:
    vector<int>st;
    vector<int>in;
    int mS;
    CustomStack(int maxSize) {
        mS = maxSize;
    }
    
    void push(int x) {
        if(st.size() >= mS) return;
        st.push_back(x);
        in.push_back(0);
    }
    
    int pop() {
        if(st.empty())return -1;
        int x = st.back();
        int i = in.back();
        st.pop_back();
        in.pop_back();
        
        if(!in.empty()){
            in.back()+=i;
        }
        return i + x;
    }
    
    void increment(int k, int val) {
        if(st.empty() || !k)return;
        if(k > in.size()){
            in.back()+=val;
        }else{
            in[k-1]+=val;
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