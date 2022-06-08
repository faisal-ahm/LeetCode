class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int i = n1-1, j = n2-1;
        string ans = "";
        int carry = 0;
        while(i >= 0 && j >= 0){
            int currSum = (num1[i--] - '0') + (num2[j--] - '0') + carry;
            carry = currSum/10;
            currSum %= 10;
            ans += '0' + currSum;
        }
        while(i >= 0){
            int currSum = (num1[i--] - '0') + carry;
            carry = currSum/10;
            currSum %= 10;
            ans += '0' + currSum;
        }
        while(j >= 0){
            int currSum = (num2[j--] - '0') + carry;
            carry = currSum/10;
            currSum %= 10;
            ans += ('0' + currSum);
        }
        if(carry){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};