class Solution {
public:
    int help(vector<int>& obstacles, vector<vector<int>>& dp, int cp = 0, int cl = 2){
        //cp current point cl current lane
        int n = obstacles.size();
        if(cp == n-1)return 0;
        if(dp[cp][cl] != -1)return dp[cp][cl];
        if(obstacles[cp + 1] != cl){
            return dp[cp][cl] = help(obstacles, dp, cp + 1, cl);
        }else{
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                int temp = INT_MAX;
                if(i != cl && obstacles[cp] != i){
                    temp = 1 + help(obstacles, dp, cp + 1, i);
                }
                ans = min(ans, temp);
            }
            return dp[cp][cl] = ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(obstacles.size(), vector<int>(4,-1));
        return help(obstacles, dp);
    }
};