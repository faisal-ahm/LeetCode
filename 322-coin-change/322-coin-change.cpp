class Solution {
public:

int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<int>dp(amount+1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            int ans1 = dp[j];
            int ans2 = coins[i - 1] > j ? -1 : dp[j - coins[i - 1]];

            if (ans1 == -1 && ans2 == -1) {
                dp[j] = -1;
            } else if (ans1 == -1) {
                dp[j] = ans2+1;
            } else if (ans2 == -1) {
                dp[j] = ans1;
            } else {
                dp[j] = min(ans2 + 1, ans1);
            }
        }
    }
    return dp[amount];
}

};