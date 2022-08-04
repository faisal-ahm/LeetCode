class Solution {
public:
    vector<vector<bool>> isPal(string& s){
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, true));
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) continue;
                if(s[i] == s[j]){
                    pal[i][j] = pal[i+1][j-1];
                }else{
                    pal[i][j] = false;
                }
            }
        }
        return pal;
    }
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return n;
        auto pal = isPal(s);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                ans += pal[i][j];
            }
        }
        return ans;
    }
};