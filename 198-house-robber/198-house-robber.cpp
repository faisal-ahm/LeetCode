class Solution {
public:
    int rob(vector<int>& nums, int start = 0) {
        
        int n = nums.size();
        /*
        if(start >= n){
            return 0;
        }
        int inc = nums[start] + rob(nums, start + 2);
        int notInc = rob(nums,start + 1);
        return max(inc, notInc);
        */
        int dp2 = 0;
        int dp1 = 0;
        int ans;
        for(int start = n-1; start >= 0; start--){
            int inc = nums[start] + dp2;
            int notInc = dp1;
            ans = max(inc, notInc);
            dp2 = dp1;
            dp1 = ans;
        }
        return dp1;
    }
};