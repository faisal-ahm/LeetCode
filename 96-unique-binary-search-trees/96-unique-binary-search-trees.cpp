class Solution {
public:
    int numTrees(int n, vector<int>& dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int numLeft = i - 1;
            int numRight = n - i;
            ans += numTrees(numLeft, dp) * numTrees(numRight, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n){
        // vector<int>dp(n + 1, -1);
        // return numTrees(n, dp);
        if(n <= 1) return 1;
        vector<int>dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = 0;
            for(int j = 1; j <= i; j++){
                int numLeft = j - 1;
                int numRight = i - j;
                dp[i] += dp[numLeft] * dp[numRight];
            }
        }
        return dp[n];
    }
};