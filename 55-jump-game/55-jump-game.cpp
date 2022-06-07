class Solution {
public:
    
    int helper(vector<int>& nums, vector<int>& dp, int start = 0){
        int n = nums.size();
        if(start >= n-1){
            return dp[start] = 1;
        }
        if(nums[start] == 0){
            return dp[start] = 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int ans = 0;
        for(int i = 1; i <= nums[start]; i++){
            if(helper(nums,dp,start + i)){
                ans = 1;
                break;
            }
        }
        return dp[start] = ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums,dp) == 0 ? false : true;
    }
};