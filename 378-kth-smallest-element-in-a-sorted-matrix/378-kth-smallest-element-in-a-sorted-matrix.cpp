class Solution {
public:
    int getRank(vector<vector<int>>& matrix, int& k){
        int ans = 0;
        for(auto i : matrix){
            for(int x : i){
                if(x <= k) ans++;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int l = mat[0][0], h = mat[n-1][n-1], m;
        while(l < h){
            m = l + (h-l)/2;
            int r = getRank(mat, m);
            if(r < k){
                l = m+1;
            }else{
                h = m;
            }
        }
        return l;
    }
};