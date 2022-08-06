class Solution {
public:
    int getNumBits(int x){
        int count = 0;
        while(x >> count)count++;
        return count;
    }
    int help(int target, vector<int>&dp){
        if(dp[target]!=0)return dp[target];
        int n = getNumBits(target);
        if((1<<n)-1 == target){
            dp[target] = n;
        }else{
            dp[target] = help((1<<n)-1 -target, dp) + n + 1;
            int x = (1 << (n - 1));
            for(int m = 0; m < n-1; m++){
                dp[target] = min(dp[target], help(target - x + (1 << m), dp) + n + m + 1);
            }
        }
        return dp[target];
    }
    int racecar(int target) {
        vector<int>dp(10001, 0);
        return help(target, dp);
    }
};