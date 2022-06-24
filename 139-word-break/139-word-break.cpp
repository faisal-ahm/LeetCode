class Solution {
public:
    int help(int i, string& s, unordered_set<string>& wordDict, vector<int>&dp){
        int n = s.size();
        if(i ==n)return 1;
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp = "";
        for(int j = i; j < n; j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(help(j + 1, s, wordDict, dp))return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1, -1);
        unordered_set<string>st;
        for(auto word : wordDict){
            st.insert(word);
        }
        return help(0, s, st,dp);
    }
};