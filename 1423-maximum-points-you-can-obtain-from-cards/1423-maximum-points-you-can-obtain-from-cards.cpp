class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>l2r(n);
        vector<int>r2l(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum+= cardPoints[i];
            l2r[i] = sum;
        }
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            sum += cardPoints[i];
            r2l[i] = sum;
        }
        int ans = INT_MIN;
        int i = k-1, j = n;
        while(i >= -1){
            int leftSum = i == -1 ? 0 : l2r[i];
            int rightSum = j == n ? 0 : r2l[j];
            ans = max(ans, rightSum + leftSum);
            i--;
            j--;
        }
        return ans;
    }
};