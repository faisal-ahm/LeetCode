class Solution {
public:
    string topost(string& s){
        auto precedence = [](char c){return c == '*' || c == '/';};
        stack<char>st;
        string ans = "";
        for(char c : s){
            if(isdigit(c)){
                ans+=c;
            }else{
                ans += '|';
                while(!st.empty() && precedence(c) <= precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        ans+='|';
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    string topost2(string& s) {
        auto precedence = [](char c){return c == '*' || c == '/';};
        stack<char> op;
        string post = "";
        for(auto c : s) 
            if(c == ' ') continue;
            else if(isdigit(c)) post += c;
            else {
                post += '|';                              // markers to separate numbers
                while(size(op) && precedence(c) <= precedence(op.top())) 
                    post += op.top(), op.pop();
                op.push(c);
            }
        
        post += '|';
        while(size(op)) 
            post += op.top(), op.pop();        
        return post;
    }

    int calculate(string s) {
        string t = topost2(s);
        stack<int>num;
        int n = t.size();
        for(int i = 0; i < n; i++){
            if(isdigit(t[i])){
                int curr = 0;
                while(i < n && isdigit(t[i])){
                    curr = curr * 10 + (t[i++]-'0');
                }
                num.push(curr);
            }else{
                int num1 = num.top(); num.pop();
                int num2 = num.top(); num.pop();
                if(t[i] == '*')      num.push(num2 * num1);
                else if(t[i] == '/') num.push(num2 / num1);
                else if(t[i] == '+') num.push(num2 + num1);
                else if(t[i] == '-') num.push(num2 - num1);
            }
        }
        return num.top();
    }
};