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
        vector<int>dp(n + 1, -1);
        return numTrees(n, dp);
    }
};