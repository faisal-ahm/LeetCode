class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), sum = 0, dup, oSum = (n*(n+1))/2;
        for(int x : nums){
            x = abs(x);
            sum+=x;
            if(x == n) x = 0;
            
            if(nums[x] < 0) dup = x ? x : n;
            else nums[x]*=-1;
        }
        return {dup, dup + oSum - sum};
    }
};