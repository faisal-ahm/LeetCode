class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> cache(rows, vector<int>(cols, 0));
        int ans = 0;
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                if(matrix[i][j] == '0') continue;
                int right = j == cols - 1 ? 0 : cache[i][j+1];
                int down = i == rows - 1 ? 0 : cache[i+1][j];
                int downRight = i == rows - 1 || j == cols - 1 ? 0 : cache[i+1][j+1];
                cache[i][j] = 1 + min(downRight, min(down, right));
                ans = max(ans, cache[i][j]);
            }
        }
        return ans * ans;
    }
};