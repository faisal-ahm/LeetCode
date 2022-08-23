class Solution {
public:
    void print(vector<vector<int>>& grid){
        for(auto i : grid){
            for(int x : i){
                cout << (x ? '.' : '#') << " ";
            }
            cout << endl;
        }
    }
    bool isClosed(vector<vector<int>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        bool ans = true;
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c] = -1;
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            ans = ans && (i > 0) && (i < m-1) && (j > 0) && (j < n-1);
            q.pop();
            if(i > 0 && grid[i-1][j] == 0){
                q.push({i-1, j});
                grid[i-1][j] = -1;
            }
            if(j > 0 && grid[i][j-1] == 0){
                q.push({i, j-1});
                grid[i][j-1] = -1;
            }
            if(i < m-1 && grid[i+1][j] == 0){
                q.push({i+1, j});
                grid[i+1][j] = -1;
            }
            if(j < n-1 && grid[i][j+1] == 0){
                q.push({i, j+1});
                grid[i][j+1] = -1;
            }
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        //print(grid);
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) continue;
                bool tmp = isClosed(grid, i, j);
                if(tmp)ans++;
            }
        }
        return ans;
    }
};