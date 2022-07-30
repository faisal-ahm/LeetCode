class Solution {
public:
    
    void helper(vector<string>& ans, string str, int n, int m){
        if(!m && !n){
            ans.push_back(str);
            return;
        }
        if(m > 0) helper(ans, str + ')', n, m-1);
        if(n > 0) helper(ans, str + '(', n-1, m + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(ans, "", n, 0);
        return ans;
    }
};