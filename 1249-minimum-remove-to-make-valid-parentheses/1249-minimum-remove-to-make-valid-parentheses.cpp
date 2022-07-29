class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != '(' && s[i] != ')') continue;
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                }else{
                    st.pop();
                }
            }
        }
        set<int>st2;
        while(!st.empty()){
            st2.insert(st.top());
            st.pop();
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(st2.find(i)!=st2.end()) continue;
            ans+=s[i];
        }
        return ans;
    }
};