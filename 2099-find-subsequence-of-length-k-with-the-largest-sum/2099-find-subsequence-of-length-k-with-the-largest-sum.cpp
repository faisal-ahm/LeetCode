class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        unordered_set<int>s;
        while(!pq.empty()){
            s.insert(pq.top().second);
            pq.pop();
        }
        vector<int>ans(k);
        int j = 0;
        for(int i = 0; i < n; i++){
            if(s.find(i) == s.end()){
                continue;
            }else{
                ans[j++] = nums[i]; 
            }
        }
        return ans;
    }
};