class Solution {
public:
    int combinationSum4(vector<int>& nums, int target, vector<int>&dp) {
        if(!target)return 1;
        if(dp[target] != -1){
            return dp[target];
        }
        int ans = 0;
        for(int x : nums){
            if(x <= target) ans += combinationSum4(nums, target - x, dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target + 1, -1);
        return combinationSum4(nums,target,dp);
    }
};