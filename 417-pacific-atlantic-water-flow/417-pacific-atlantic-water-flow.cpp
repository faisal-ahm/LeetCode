class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<pair<int,int>>>grid(m, vector<pair<int,int>>(n, {0,0}));
        queue<pair<int,int>>q;

        //processing pacific
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!i || !j){
                    q.push({i, j});
                    grid[i][j].first = 1;
                }
            }
        }
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();

            if(i > 0 && !grid[i-1][j].first && h[i-1][j] >= h[i][j]){
                q.push({i-1, j});
                grid[i-1][j].first = 1;
            }
            if(j > 0 && !grid[i][j-1].first && h[i][j-1] >= h[i][j]){
                q.push({i, j-1});
                grid[i][j-1].first = 1;
            }
            if(i < m-1 && !grid[i+1][j].first && h[i+1][j] >= h[i][j]){
                q.push({i+1, j});
                grid[i+1][j].first = 1;
            }
            if(j < n-1 && !grid[i][j+1].first && h[i][j+1] >= h[i][j]){
                q.push({i, j+1});
                grid[i][j+1].first = 1;
            }
        }


        //processing atlantic
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i==(m-1) || j==(n-1)){
                    q.push({i, j});
                    grid[i][j].second = 1;
                }
            }
        }
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();

            if(i > 0 && !grid[i-1][j].second && h[i-1][j] >= h[i][j]){
                q.push({i-1, j});
                grid[i-1][j].second = 1;
            }
            if(j > 0 && !grid[i][j-1].second && h[i][j-1] >= h[i][j]){
                q.push({i, j-1});
                grid[i][j-1].second = 1;
            }
            if(i < m-1 && !grid[i+1][j].second && h[i+1][j] >= h[i][j]){
                q.push({i+1, j});
                grid[i+1][j].second = 1;
            }
            if(j < n-1 && !grid[i][j+1].second && h[i][j+1] >= h[i][j]){
                q.push({i, j+1});
                grid[i][j+1].second = 1;
            }
        }

        vector<vector<int>>ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j].first && grid[i][j].second) ans.push_back({i, j});
            }
        }
        return ans;
    }
};