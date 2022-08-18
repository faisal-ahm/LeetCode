class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j]){
                    M[i][j] = -1;
                }else{
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            auto front = q.front();
            int i = front.first, j = front.second, val = M[i][j];
            q.pop();
            if(i > 0 && M[i-1][j] == -1){
                M[i-1][j] = val + 1;
                q.push({i-1, j});
            }
            if(j > 0 && M[i][j-1] == -1){
                M[i][j-1] = val + 1;
                q.push({i, j-1});
            }
            if(i < m-1 && M[i+1][j] == -1){
                M[i+1][j] = val + 1;
                q.push({i+1, j});
            }
            if(j < n-1 && M[i][j+1] == -1){
                M[i][j+1] = val + 1;
                q.push({i, j+1});
            }
        }
        return M;
    }
};