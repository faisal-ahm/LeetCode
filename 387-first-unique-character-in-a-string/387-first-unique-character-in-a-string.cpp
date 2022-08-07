class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), ans = -1;
        unordered_map<char,int>freq;
        for(char c : s) freq[c]++;
        for(int i = 0; i < n; i++){
            if(freq[s[i]] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};