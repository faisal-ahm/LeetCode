class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    q.push({i, j});
                }else{
                    grid[i][j] = -1;
                }
            }
        }
        
        while(q.size()){
            int i = q.front().first, j = q.front().second, val = grid[i][j];
            q.pop();
            if(i > 0 && grid[i-1][j] == -1){
                q.push({i-1, j});
                grid[i-1][j] = val+1;
            }
            if(j > 0 && grid[i][j-1] == -1){
                q.push({i, j-1});
                grid[i][j-1] = val+1;
            }
            if(i < m-1 && grid[i+1][j] == -1){
                q.push({i+1, j});
                grid[i+1][j] = val+1;
            }
            if(j < n-1 && grid[i][j+1] == -1){
                q.push({i, j+1});
                grid[i][j+1] = val+1;
            }
        }
        return grid;
    }
};