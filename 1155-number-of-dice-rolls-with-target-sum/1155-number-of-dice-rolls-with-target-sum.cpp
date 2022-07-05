
class Solution {
public:
    
int numRollsToTarget(int n, int k, int target) {
    int mod = 1000000007;
    vector<int>dp(target + 1);
    for(int i = 0; i <= n; i++){
        for(int j = target; j >= 0; j--){
            if(i == 0){
                dp[j] = 0;
                if(j == 0) dp[j] = 1;
                continue;
            }
            int ans = 0;
            for(int m = 1; m <= k && m <= j; m++){
                ans += dp[j - m]%(mod);
                ans %= mod;
            }
            dp[j] = ans;
        }
    }
        
    return dp[target];
}
};