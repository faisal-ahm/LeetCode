class Solution {
public:
    
    vector<int>kmp(string&s){
        int n = s.size();
        vector<int>lps(n);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = ++j;
                i++;
            }else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(string s) {
        vector<int>lps = kmp(s);
        int n = s.size();
        return (lps[n-1] != 0 && lps[n-1]%(n-lps[n-1]) == 0);
    }
};