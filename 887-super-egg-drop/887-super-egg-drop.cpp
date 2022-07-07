class Solution {
public:
    int superEggDrop(int k, int n, vector<vector<int>>&dp) {
        if(n <= 1 || k == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = INT_MAX, l = 1, r = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            int brk = 1 + superEggDrop(k-1, mid-1,dp);
            int nbrk = 1 + superEggDrop(k, n-mid, dp);
            int temp;
            if(brk < nbrk){
                temp = nbrk;
                l = mid + 1;
            }else{
                temp = brk;
                r = mid-1;
            }
            ans = min(ans, temp);
        }

        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n){
        vector<vector<int>>dp(k+1, vector<int>(n+1, -1));
        return superEggDrop(k,n,dp);
    }
};