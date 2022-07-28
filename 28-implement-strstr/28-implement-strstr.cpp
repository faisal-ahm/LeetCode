class Solution {
public:
    vector<int> kmp(string& s){
        int n = s.size();
        vector<int>lps(n);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                j++;
                i++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        if(n == 0)return -1;
        if(m == 0)return 0;
        vector<int>lps = kmp(needle);
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            
            if(j == m)return i-j;
            
            if(i < n && haystack[i] != needle[j]){
                if(j == 0){
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
        }
        return -1;
    }
};