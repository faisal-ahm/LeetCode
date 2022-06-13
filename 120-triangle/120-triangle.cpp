class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n);
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                if(i == n-1){
                    dp[j] = triangle[i][j];
                }else{
                    int left = dp[j];
                    int right = dp[j+1];
                    dp[j] = triangle[i][j] + min(left, right);
                }
            }
        }
        return dp[0];
    }
};