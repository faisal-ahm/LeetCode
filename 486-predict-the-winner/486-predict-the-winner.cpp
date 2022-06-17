class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        for(int s = n-1; s >= 0; s--){
            for(int e = s; e < n; e++){
                if(e == s){
                    dp[e] = nums[s];
                    continue;
                }
                int a = nums[s] - dp[e];
                int b = nums[e] - dp[e-1];
                dp[e] = max(a,b);
            }
        }
        return dp[n-1] >= 0;
    }
};