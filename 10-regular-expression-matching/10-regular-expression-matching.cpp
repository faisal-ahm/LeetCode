class Solution {
public:
    void printV(vector<vector<bool>>&v){
        for(auto v2 : v){
            for(auto b : v2){
                char c = b ? '@' : '.';
                cout << c << " ";
            }
            cout << endl;
        }
    }
    bool isAlpha(char c){
        return c >= 'a' && c <= 'z';
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            char pc = p[i-1];
            dp[i][0] = !isAlpha(pc) && ((pc!='.') && dp[i-2][0]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char pc = p[i-1], sc = s[j-1];
                if(isAlpha(pc)){
                    dp[i][j] = (pc == sc) && dp[i-1][j-1];
                }else{
                    if(pc == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = dp[i-2][j] || ((p[i-2] == sc) || (p[i-2] == '.') ? dp[i][j-1] : dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n][m];
    }
};