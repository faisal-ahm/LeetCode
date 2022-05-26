class Solution {
public:
    
    int numDecodings(string s) {
        /*
        if(start >= s.size()){
            return 1;
        }
        if(s[start] == '0'){
            return 0;
        }
        if(start == s.size()-1){
            return 1;
        }
        int oneD = numDecodings(s, start + 1);
        int twoD = start < (s.size()-1) && ((s[start]-'0')*10 + (s[start + 1] - '0')) <= 26 ? numDecodings(s,start + 2) : 0;
        return oneD + twoD;
        */
        int n = s.size();
        
        int onePos = s[n-1] == '0' ? 0 : 1;
        int twoPos = 1;
        int c;
        for(int start = n-2; start >= 0; start--){
            
            if(s[start] == '0'){
                c = 0;
                twoPos = onePos;
                onePos = c;
                continue;
            }
            int oneD = onePos;
            int twoD = start < (n-1) && ((s[start]-'0')*10 + (s[start + 1] - '0')) <= 26 ? twoPos : 0;
            c = oneD + twoD;
            twoPos = onePos;
            onePos = c;
        }
        return onePos;
        
    }
};