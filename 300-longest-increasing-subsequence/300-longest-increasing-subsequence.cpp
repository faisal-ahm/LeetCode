class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maximum = 0, n = nums.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            int currMax = 0;
            int j = 0;
            while(j < i){
                if(nums[j] < nums[i]) currMax = max(currMax, dp[j]);
                j++;
            }
            dp[i] = 1 + currMax;
            maximum = max(dp[i], maximum);
        }
        return maximum;
    }
};