class Solution {
public:
    int value(char c){
        switch(c){
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n = s.size(), ans = 0;
        for(int i = n-1; i >= 0; i--){
            int val = value(s[i]);
            if(i!=n-1 && val < value(s[i+1])){
                ans-=val;
            }else{
                ans+=val;
            }
        }
        return ans;
    }
};