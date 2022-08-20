class Solution {
public:
    void print(vector<vector<int>>& v){
        for(auto& i : v){
            for(auto& x : i){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1) return grid[0][0] == 0 ? 1 : -1;
        if(grid[n-1][n-1]) return -1;
        for(auto& i : grid){
            for(int& x : i){
                x = x ? -2 : -1;
            }
        }
        grid[n-1][n-1] = grid[n-1][n-1] == -2 ? grid[n-1][n-1] : 1;
        queue<pair<int,int>>q;
        q.push({n-1,n-1});
        while(q.size()){
            auto front = q.front();
            q.pop();
            int i = front.first, j = front.second;
            if(i < n-1 && grid[i+1][j] == -1){
                grid[i+1][j] = grid[i][j] + 1;//down
                q.push({i+1, j});
            }
            if(j < n-1 && grid[i][j+1] == -1){
                grid[i][j+1] = grid[i][j] + 1;//right
                q.push({i, j+1});
            }
            if(i > 0 && grid[i-1][j] == -1){
                grid[i-1][j] = grid[i][j] + 1;//up
                q.push({i-1, j});
            }
            if(j > 0 && grid[i][j-1] == -1){
                grid[i][j-1] = grid[i][j] + 1;//left
                q.push({i, j-1});
            }
            if(i < n-1 && j < n-1 && grid[i+1][j+1] == -1){
                grid[i+1][j+1] = grid[i][j] + 1;//down right
                q.push({i+1, j+1});
            }
            if(i > 0 && j < n-1 && grid[i-1][j+1] == -1){
                grid[i-1][j+1] = grid[i][j] + 1;//up right
                q.push({i-1, j+1});
            }
            if(i > 0 && j > 0 && grid[i-1][j-1] == -1){
                grid[i-1][j-1] = grid[i][j] + 1;//up left
                q.push({i-1, j-1});
            }
            if(i < n-1 && j > 0 && grid[i+1][j-1] == -1){
                grid[i+1][j-1] = grid[i][j] + 1;//down left
                q.push({i+1, j-1});
            }
        }
        print(grid);
        return max(-1, grid[0][0]);
    }
};