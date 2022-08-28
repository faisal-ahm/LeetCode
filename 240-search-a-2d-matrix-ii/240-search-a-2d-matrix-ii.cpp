class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = n-1;
        while(j >= 0 && i < m){
            if(mat[i][j] > t){
                j--;
            }else if(mat[i][j] < t){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};