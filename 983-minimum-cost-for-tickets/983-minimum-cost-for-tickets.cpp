class Solution {
public:
    int help(vector<int>d, vector<int>c, int i, vector<int>&dp){
        
        int n = d.size();
        if(i >= n)return 0;
        if(dp[i] != -1) return dp[i];
        int currDay = d[i];
        int ans = c[0] + help(d, c, i + 1, dp);
        int j = i; 
        while(j < n && d[j] <= currDay + 6) j++;
        ans = min(ans,c[1] + help(d, c, j, dp));
        j = i; 
        while(j < n && d[j] <= currDay + 29) j++;
        ans = min(ans,c[2] + help(d, c, j, dp));
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size() + 1, -1);
        return help(days,costs,0,dp);
    }
};