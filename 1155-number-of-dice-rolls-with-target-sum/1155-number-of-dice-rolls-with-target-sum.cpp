
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(i == 0){
                    dp[i][j] = 0;
                    if(j == 0) dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = 0;
                for(int m = 1; m <= k && m <= j; m++){
                    dp[i][j] += dp[i - 1][j - m]%(mod);
                    dp[i][j] %= mod;
                }
            }
        }
        
        return dp[n][target];
        
        
        if(n == 0){
            if(target == 0)return 1;
            return 0;
        }
        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans += numRollsToTarget(n-1, k, target - i);
        }
        return ans;
    }
};