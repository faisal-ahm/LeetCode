class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26);
        int n = s.size();
        for(int i = 0; i < n; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        vector<bool>vis(26,false);
        string ans = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(vis[c-'a']){
                continue;
            }
            while(ans.size() && ans.back() > c && lastIndex[ans.back() - 'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            vis[c-'a'] = true;
        }
        return ans;
    }
};