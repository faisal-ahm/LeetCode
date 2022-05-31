class Solution {
public:
    int lengthOfLIS(vector<int>& nums, vector<vector<int>>&dp, int index = 0, int prevI = -1) {
        if(dp[index][prevI + 1] != -1){
            return dp[index][prevI + 1];
        }
        int n = nums.size();
        
        if(index == n){
            return dp[index][prevI + 1] = 0;
        }
        int inc = nums[index] > (prevI == -1 ? INT_MIN : nums[prevI]) ?1 + lengthOfLIS(nums, dp, index + 1, index) : 0;
        int nInc = lengthOfLIS(nums, dp, index + 1, prevI);
        return dp[index][prevI + 1] = max(nInc, inc);
    }
    int lengthOfLIS(vector<int>& nums){
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lengthOfLIS(nums,dp);
    }
};