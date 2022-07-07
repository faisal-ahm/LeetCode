class Solution {
public:
    int help(vector<int>& nums, int s, int e, vector<vector<int>>& dp){
        if(e < s) return 0;
        int n = nums.size();
        if(s == e){
            int lMul = s == 0 ? 1 : nums[s-1];
            int rMul = e == n-1 ? 1 : nums[e+1];
            return lMul * nums[s] * rMul;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        
        int lMul = s == 0 ? 1 : nums[s-1];
        int rMul = e == n-1 ? 1 : nums[e+1];
        int ans = INT_MIN;
        for(int i = s; i <= e; i++){
            int lPart = help(nums, s, i - 1, dp);
            int rPart = help(nums, i + 1, e, dp);
            
            ans = max(ans, lPart + rPart + (lMul * nums[i] * rMul));
        }
        return dp[s][e] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return help(nums, 0, nums.size()-1, dp);
    }
};