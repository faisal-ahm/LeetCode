class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = sum += nums[i];
        }
        return nums;
        
    }
};