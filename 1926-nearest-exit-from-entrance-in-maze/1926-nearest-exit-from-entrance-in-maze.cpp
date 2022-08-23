class Solution {
public:
    void print(vector<vector<int>>& grid){
        for(auto& i : grid){
            for(int x : i){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entr) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>>grid(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(maze[i][j] == '+') {
                    grid[i][j] = -2;
                    continue;
                }
                
                grid[i][j] = -1;
            }
        }
        
        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == entr[0] && j == entr[1]) || maze[i][j] == '+') continue;
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            int i = q.front().first, j = q.front().second, val = grid[i][j];
            q.pop();
            if(i > 0 && grid[i-1][j] == -1){
                grid[i-1][j] = val + 1;
                q.push({i-1, j});
            }
            if(j > 0 && grid[i][j-1] == -1){
                grid[i][j-1] = val + 1;
                q.push({i, j-1});
            }
            if(i < m-1 && grid[i+1][j] == -1){
                grid[i+1][j] = val + 1;
                q.push({i+1, j});
            }
            if(j < n-1 && grid[i][j+1] == -1){
                grid[i][j+1] = val + 1;
                q.push({i, j+1});
            }
        }
        
        return grid[entr[0]][entr[1]];
    }
};