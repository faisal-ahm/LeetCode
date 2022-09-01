class Solution {
public:
    vector<vector<bool>> isPal(string& s){
        int n = s.size();
        vector<vector<bool>> ans(n, vector<bool>(n, true));
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                ans[i][j] = (i == j) || (s[i] == s[j] && ans[i+1][j-1]);
            }
        }
        return ans;
    }
    
    void help(string& s, vector<string>& path, vector<vector<string>>& ans, vector<vector<bool>>& isPal, int st){
        int n = s.size();
        if(st == n){
            ans.push_back(path);
            return;
        }
        for(int i = st; i < n; i++){
            if(!isPal[st][i]) continue;
            path.push_back(s.substr(st, i-st+1));
            help(s, path, ans, isPal, i+1);
            path.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        auto ispal = isPal(s);
        vector<vector<string>>ans;
        vector<string>path;
        help(s, path, ans, ispal, 0);
        
        return ans;
    }
};