class Solution {
public:
    int coinChange(vector<int>& coins, int amount, int start) {
        int n = coins.size();
        if(amount == 0){
            return 0;
        }
        if(start == n){
            return -1;
        }
        int notIncluding = coinChange(coins, amount, start + 1);
        int including = amount < coins[start] ? -1 : coinChange(coins, amount - coins[start], start);
        if(including != -1 && notIncluding != -1){
            return min(including + 1, notIncluding);
        }else if(including != -1){
            return including + 1;
        }else if(notIncluding != -1){
            return notIncluding;
        }else{
            return -1;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount + 1);
        for(int i = n; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                if(j == 0){
                    dp[j] = 0;
                    continue;
                }
                if(i == n){
                    dp[j] = -1;
                    continue;
                }
                int notInc = dp[j];
                int inc = j < coins[i] ? -1 : dp[j - coins[i]];
                if(notInc == -1 && inc == -1){
                    dp[j] = -1;
                }else if(notInc == -1){
                    dp[j] = inc + 1;
                }else if(inc == -1){
                    dp[j] = notInc;
                }else{
                    dp[j] = min(inc + 1, notInc);
                }
                
            }
        }
        return dp[amount];
    }
};