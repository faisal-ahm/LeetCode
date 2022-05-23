class Solution {
public:
    void helper(vector<vector<int>> &grid, int i, int j, int &curr) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    grid[i][j] = -1;
    curr += 1;
    if (i != 0 && grid[i - 1][j] == 1) {
        helper(grid, i - 1, j, curr);
    }
    if (i != numRows - 1 && grid[i + 1][j] == 1) {
        helper(grid, i + 1, j, curr);
    }
    if (j != numCols - 1 && grid[i][j + 1] == 1) {
        helper(grid, i, j + 1, curr);
    }
    if (j != 0 && grid[i][j - 1] == 1) {
        helper(grid, i, j - 1, curr);
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = 0;
    int numRows = grid.size();
    int numCols = grid[0].size();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int curr = 0;
            if (grid[i][j] == 1) {
                grid[i][j] = -1;
                curr += 1;
                if (i != 0 && grid[i - 1][j] == 1) {
                    helper(grid, i - 1, j, curr);
                }
                if (i != numRows - 1 && grid[i + 1][j] == 1) {
                    helper(grid, i + 1, j, curr);
                }
                if (j != numCols - 1 && grid[i][j + 1] == 1) {
                    helper(grid, i, j + 1, curr);
                }
                if (j != 0 && grid[i][j - 1] == 1) {
                    helper(grid, i, j - 1, curr);
                }
                ans = max(ans, curr);
            }
        }
    }
    return ans;
}
};