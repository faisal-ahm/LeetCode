class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans, pos(26,-1);
        int n = s.size();
        for(int i = 0; i < n; i++) pos[s[i]-'a'] = i;
        int end = INT_MIN, size = 0;
        for(int i = 0; i < n; i++){
            end = max(end, pos[s[i] - 'a']);
            size++;
            if(i == end){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};