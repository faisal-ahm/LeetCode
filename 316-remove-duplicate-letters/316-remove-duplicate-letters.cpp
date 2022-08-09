class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool>vis(26, false);
        vector<int>idx(26, -1);//last index of each letter in s
        for(int i = 0; i < n; i++){
            idx[s[i]-'a'] = i;
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(vis[s[i]-'a']) continue;
            while(!ans.empty() && ans.back() > s[i] && idx[ans.back()-'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans+=s[i];
            vis[s[i]-'a'] = true;
        }
        return ans;
    }
};