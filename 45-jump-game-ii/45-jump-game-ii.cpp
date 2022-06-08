class Solution {
public:
    
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n);
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        int range = i + nums[i];
        if(range >= n-1){
            dp[i] = 1;
            continue;
        }
        dp[i] = INT_MAX;
        for(int j = range; j > i; j--){
            if(dp[j] == INT_MAX){
                continue;
            }
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[0];
}
};