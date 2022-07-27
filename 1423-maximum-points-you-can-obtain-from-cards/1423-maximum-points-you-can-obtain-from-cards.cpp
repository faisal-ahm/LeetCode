class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, n = cardPoints.size();
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }
        int i = k, j = n, rightSum = 0, ans = INT_MIN;
        while(i >= 0){
            leftSum -= (i == k ? 0 : cardPoints[i]);
            rightSum += (j == n ? 0 : cardPoints[j]);
            ans = max(ans, leftSum + rightSum);
            i--;
            j--;
        }
        return ans;
    }
};