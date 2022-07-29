class Solution {
public:
    void printV(vector<vector<bool>>&v){
        int n = v.size(), m = v[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j < i){
                    cout<< "  ";
                }else{
                    if(v[i][j]){
                        cout << "T ";
                    }else{
                        cout << ". ";
                    }
                }
            }
            cout << endl;
        }
    }
    vector<vector<bool>> isPal(string& s){
        int n = s.size();
        vector<vector<bool>>ans(n, vector<bool>(n, true));
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    ans[i][j] = ans[i+1][j-1];
                }else{
                    ans[i][j] = false;
                }
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        auto pal = isPal(s);
        pair<int,int>startAndEnd = {0,0};
        int minSize = 1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(!pal[i][j]) continue;
                int size = j - i + 1;
                if(size > minSize){
                    minSize = size;
                    startAndEnd = {i, j};
                }
            }
        }
        return s.substr(startAndEnd.first, startAndEnd.second - startAndEnd.first + 1);
    }
};