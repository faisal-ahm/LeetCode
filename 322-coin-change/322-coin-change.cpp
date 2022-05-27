class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1,-1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            int ans1 = dp[i - 1][j];
            int ans2 = coins[i - 1] > j ? -1 : dp[i][j - coins[i - 1]];

            if (ans1 == -1 && ans2 == -1) {
                dp[i][j] = -1;
            } else if (ans1 == -1) {
                dp[i][j] = ans2+1;
            } else if (ans2 == -1) {
                dp[i][j] = ans1;
            } else {
                dp[i][j] = min(ans2 + 1, ans1);
            }
        }
    }
    return dp[n][amount];
}

};