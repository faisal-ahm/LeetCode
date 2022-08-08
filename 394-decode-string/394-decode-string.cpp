class Solution {
public:
    string help(string& s, int& i){
        int n = 0;
        string word = "";
        for(; i < s.size(); i++){
            char c = s[i];
            if(c == ']'){
                return word;
            }else if(c == '['){
                i++;
                string res = help(s,i);
                while(n){
                    word += res;
                    n--;
                }
            }else if(isdigit(c)){
                n = n*10 + c-'0';
            }else{
                word+=c;
            }
        }
        return word;
    }
    string decodeString(string s) {
        int i = 0;
        return help(s,i);
    }
};