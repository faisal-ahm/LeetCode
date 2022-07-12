class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
                continue;
            }
            int p = i + 1, q = j;
            while(p < q){
                if(s[p] == s[q]){
                    p++;
                    q--;
                    continue;
                }
                break;
            }
            if(p >= q) return true;
            
            p = i, q = j - 1;
            while(p < q){
                if(s[p] == s[q]){
                    p++;
                    q--;
                    continue;
                }
                break;
            }
            return p >= q;
        }
        return true;
    }
};