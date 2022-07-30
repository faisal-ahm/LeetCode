class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            int digit = s[i] - '0';
            if((digit&1) == (i&1)) count1++;
            else count2++;
        }
        return min(count1, count2);
    }
};