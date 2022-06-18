class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), numFresh = 0;
        queue<pair<int,int>>q;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    numFresh++;
                }
            }
        }
        if(numFresh==0){
            return 0;
        }
        q.push({-1,-1});
        int ans = -1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front.first == -1){
                ans++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }else{
                int x = front.first, y = front.second;
                if(x > 0 && grid[x-1][y] ==1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                    numFresh--;
                }
                if(x < numRows-1 && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                    numFresh--;
                }
                if(y > 0 && grid[x][y-1] ==1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                    numFresh--;
                }
                if(y < numCols-1 && grid[x][y+1] ==1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    numFresh--;
                }
            }
        }
        return numFresh == 0 ? ans : -1;
    }
};