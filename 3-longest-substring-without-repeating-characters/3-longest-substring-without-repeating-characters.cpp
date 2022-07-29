class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;
        set<char>st;
        st.insert(s[0]);
        int ans = 1, i = 1, j = 0;
        while(i < n){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                ans = ans > st.size() ? ans : st.size();
                i++;
            }else{
                while(s[j]!=s[i]){
                    st.erase(s[j++]);
                }
                st.erase(s[j++]);
            }
        }
        return ans;
    }
};