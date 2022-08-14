class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j < n; j++){
                if(i == n-1){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int left = j == 0 ? INT_MAX : dp[i+1][j-1];
                int down = dp[i+1][j];
                int right = j == n-1 ? INT_MAX : dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + min(down, min(left, right));
            }
        }
        int ans = INT_MAX;
        for(int x : dp[0]){
            ans = min(ans, x);
        }
        return ans;
    }
};