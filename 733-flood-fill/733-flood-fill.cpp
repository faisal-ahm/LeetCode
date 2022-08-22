class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>>q;
        int tempcolor = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = -1;
        while(q.size()){
            auto i = q.front().first, j = q.front().second;
            q.pop();
            if(i > 0 && image[i-1][j] == tempcolor){
                q.push({i-1, j});
                image[i-1][j] = -1;
            }
            if(j > 0 && image[i][j-1] == tempcolor){
                q.push({i, j-1});
                image[i][j-1] = -1;
                
            }
            if(i < m-1 && image[i+1][j] == tempcolor){
                q.push({i+1, j});
                image[i+1][j] = -1;
            }
            if(j < n-1 && image[i][j+1] == tempcolor){
                q.push({i, j+1});
                image[i][j+1] = -1;
            }
        }
        for(auto& i : image){
            for(int& x : i){
                if(x == -1) x = color;
            }
        }
        return image;
    }
};