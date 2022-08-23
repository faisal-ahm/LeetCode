class Solution {
public:
    bool isSub(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c){
        int m = grid2.size(), n = grid2[0].size();
        int ans = true;
        queue<pair<int,int>>q;
        q.push({r,c});
        grid2[r][c] = -1;
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            ans = ans && grid1[i][j] == 1;
            q.pop();
            if(i > 0 && grid2[i-1][j] == 1){
                q.push({i-1, j});
                grid2[i-1][j] = -1;
            }
            if(j > 0 && grid2[i][j-1] == 1){
                q.push({i, j-1});
                grid2[i][j-1] = -1;
            }
            if(i < m-1 && grid2[i+1][j] == 1){
                q.push({i+1, j});
                grid2[i+1][j] = -1;
            }
            if(j < n-1 && grid2[i][j+1] == 1){
                q.push({i, j+1});
                grid2[i][j+1] = -1;
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int ans = 0;
        int m = grid2.size(), n = grid2[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] != 1) continue;
                auto tmp = isSub(grid1,grid2,i,j);
                if(tmp)ans++;
            }
        }
        return ans;
    }
};