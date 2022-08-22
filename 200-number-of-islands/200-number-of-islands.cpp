class Solution {
public:
    void help(vector<vector<char>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c] = '2';
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(i > 0 && grid[i-1][j] == '1'){
                q.push({i-1, j});
                grid[i-1][j] = '2';
            }
            if(j > 0 && grid[i][j-1] == '1'){
                q.push({i, j-1});
                grid[i][j-1] = '2';
            }
            if(i < m-1 && grid[i+1][j] == '1'){
                q.push({i+1, j});
                grid[i+1][j] = '2';
            }
            if(j < n-1 && grid[i][j+1] == '1'){
                q.push({i, j+1});
                grid[i][j+1] = '2';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]!='1') continue;
                ans++;
                help(grid, i, j);
            }
        }
        return ans;
    }
};