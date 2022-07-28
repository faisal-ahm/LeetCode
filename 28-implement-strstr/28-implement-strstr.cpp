class Solution {
public:
    vector<int> getLPS(string& s){
        int n = s.size();
        vector<int>lps(n, 0);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                j++;
                i++;
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        
        if(n==0) return -1;
        if(m==0) return 0;
        
        int i = 0, j = 0;
        
        vector<int> lps = getLPS(needle);
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            
            if(j == m)return i-j;
            
            if(i < n && haystack[i] != needle[j]){
                if(j > 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};