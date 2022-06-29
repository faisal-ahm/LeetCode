class Solution {
public:
    int help(vector<int>& values, vector<vector<int>>& dp, int s, int e){
        if(e-s <= 1) return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int ans = INT_MAX;
        for(int cut = s + 1; cut < e; cut++){
            int score = values[cut] * values[s] * values[e];
            ans = min(ans, score + help(values, dp, cut, e) + help(values, dp, s, cut));
        }
        return dp[s][e] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return help(values, dp, 0, n - 1);
    }
};