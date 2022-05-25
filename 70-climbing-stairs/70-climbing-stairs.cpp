class Solution {
public:
    
    
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        vector<int>dp(n+1);
        for(int i = 1; i <= n; i++){
            if(i <= 2){
                dp[i] = i;
            }else{
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};