class Solution {
public:
    void reverse(string& s, int i, int j){
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int n = s.size(), i = 0, j = n-1;
        while(s[i] == ' ')i++;
        while(s[j] == ' ')j--;
        n = j-i+1;
        string ans = s.substr(i, n);
        reverse(ans, 0, n-1);
        i = 0;
        while(i < n){
            if(ans[i] == ' '){
                i++;
                continue;
            }
            j = i;
            while(j < n && ans[j] != ' ')j++;
            reverse(ans, i, j-1);
            i = j;
        }
        string ans2 = "";
        n = ans.size(), i = 0;
        while(i < n){
            if(ans[i] == ' '){
                i++;
                continue;
            }
            ans2 += ans[i++];
            if(i!= n && ans[i] == ' ') ans2+= ' ';
        }
        return ans2;
    }
};