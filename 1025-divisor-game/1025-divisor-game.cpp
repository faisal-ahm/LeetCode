class Solution {
public:
    bool divisorGame(int n) {
        if(n<=1)return false;
        // for(int i = 1; i < n; i++){
        //     if(n%i == 0 && !divisorGame(n-i)){
        //         return true;
        //     }
        // }
        // return false;
        vector<bool>dp(n + 1, false);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i%j == 0 && !dp[i-j]){
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp[n];
    }
};