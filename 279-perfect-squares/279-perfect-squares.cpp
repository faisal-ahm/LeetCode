class Solution {
public:
    int numSquares(int n) {
        if(n == 0)return 0;
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i],1 + dp[i - (j*j)]);
            }
        }
        return dp[n];
    }
};