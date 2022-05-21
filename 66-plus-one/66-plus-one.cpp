class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int n = digits.size();
        int i;
        int carry = 0;
        for(i = 0; i < n; i++){
            digits[i] += 1;
            digits[i] %= 10;
            if(digits[i] != 0){
                break;
            }
        }
        if(digits[n-1] == 0){
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};