class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            currSum = currSum < 0 ? 0 : currSum;
        }
        return maxSum;
    }
};