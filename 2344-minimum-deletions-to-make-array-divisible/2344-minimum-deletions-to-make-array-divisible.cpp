class Solution {
public:
    int getGCD(int a, int b){
        int divisor = min(a,b), dividend = max(a,b);
        if(divisor == 0) return dividend;
        while(divisor != 0){
            int r = dividend%divisor;
            dividend = divisor;
            divisor = r;
        }
        return dividend;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int GCD = numsDivide[0];
        for(int x : numsDivide){
            GCD = getGCD(GCD, x);
        }
        for(int i = 0; i < nums.size() && nums[i] <= GCD; i++){
            if(GCD % nums[i] == 0)return i;
        }
        return -1;
    }
};