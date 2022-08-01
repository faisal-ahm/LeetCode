class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), originalSum = (n*(n+1))/2, sum = 0;
        for(int x : nums){
            sum += x;
        }
        return originalSum - sum;
    }
};