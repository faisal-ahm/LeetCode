class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n);
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                dp[j] = i == m-1 || j == n-1 ? 1 : dp[j] + dp[j+1];
            }
        }
        return dp[0];
    }
};