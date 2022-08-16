class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int x : stones){
            q.push(x);
        }
        while(q.size()){
            if(q.size() == 1) return q.top();
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if(x > y) q.push(x-y);
        }
        return 0;
    }
};