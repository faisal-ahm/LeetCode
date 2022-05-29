class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //removing duplicates and recording frequencies
        vector<int>newNums;
        unordered_map<int,int>freq;
        for(int x : nums){
            if(freq.find(x) == freq.end()){
                newNums.push_back(x);
            }
            freq[x]++;
        }
        int n = newNums.size();
        vector<int>dp(n + 2);
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i = n-1; i >= 0; i--){
            if(i == n-1){
                dp[i] = newNums[i] * freq[newNums[i]];
                continue;
            }
            int inc = newNums[i+1] == newNums[i] + 1 ? dp[i+2] : dp[i+1];
            inc += newNums[i] * freq[newNums[i]];
            int nInc = dp[i+1];
            dp[i] = max(inc, nInc);
        }
        return dp[0];
    }
};