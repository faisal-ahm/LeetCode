class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size(), n = grid[0].size(), c1 = 0, c0 = 0;;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    c1++;
                    q.push({i,j});
                }else{
                    c0++;
                    grid[i][j] = -1;
                }
            }
        }
        if(!c1 || !c0) return -1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first, j = front.second, val = grid[i][j];
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
        int ans = 1;
        for(vector<int> i : grid){
            for(int x : i){
                ans = max(ans, x);
            }
        }
        return ans;
    }
};