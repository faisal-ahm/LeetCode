class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int ans = 0;
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                if(!matrix[i][j]) continue;
                int down = i == rows-1 ? 0 : dp[i+1][j];
                int right = j == cols-1 ? 0 : dp[i][j+1];
                int downRight = (i == rows-1)||(j == cols-1) ? 0 : dp[i+1][j+1];
                dp[i][j] = 1 + min(min(right,down), downRight);
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};