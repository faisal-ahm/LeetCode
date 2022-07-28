class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size(), i = 0;
        while(i < n){
            if(haystack[i] != needle[0]){
                i++;
                continue;
            }
            int j = 0;
            cout << i << " -> " ;
            while((i+j)<n && j<m && haystack[i+j] == needle[j]){
                cout << j << " ";
                j++;
            }
            cout << j << endl;
            if(j==m)return i;
            i++;
        }
        return -1;
    }
};