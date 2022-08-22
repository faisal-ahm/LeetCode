class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]) continue;
                if(i == 0 || !grid[i-1][j])ans++;
                if(j == 0 || !grid[i][j-1])ans++;
                if(i == m-1 || !grid[i+1][j])ans++;
                if(j == n-1 || !grid[i][j+1])ans++;
            }
        }
        return ans;
    }
};