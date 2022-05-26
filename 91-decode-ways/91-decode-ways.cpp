class Solution {
public:
    
    int numDecodings(string s) {
        /*
        if(start >= s.size()){
            return 1;
        }
        if(s[start] == '0'){
            return 0;
        }
        if(start == s.size()-1){
            return 1;
        }
        int oneD = numDecodings(s, start + 1);
        int twoD = start < (s.size()-1) && ((s[start]-'0')*10 + (s[start + 1] - '0')) <= 26 ? numDecodings(s,start + 2) : 0;
        return oneD + twoD;
        */
        int n = s.size();
        
        vector<int>dp(n+1);
        for(int start = n; start >= 0; start--){
            if(start >= n){
                dp[start] = 1;
                continue;
            }
            if(s[start] == '0'){
                dp[start] = 0;
                continue;
            }
            if(start == n-1){
                dp[start] = 1;
                continue;
            }
            int oneD = dp[start + 1];
            int twoD = start < (n-1) && ((s[start]-'0')*10 + (s[start + 1] - '0')) <= 26 ? dp[start + 2] : 0;
            dp[start] = oneD + twoD;
        }
        return dp[0];
        
    }
};