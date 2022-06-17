class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n));
        for(int s = n-1; s >= 0; s--){
            for(int e = s; e < n; e++){
                if(e == s){
                    dp[s][e] = nums[s];
                    continue;
                }
                int a = nums[s] - dp[s+1][e];
                int b = nums[e] - dp[s][e-1];
                dp[s][e] = max(a,b);
            }
        }
        return dp[0][n-1] >= 0;
    }
};