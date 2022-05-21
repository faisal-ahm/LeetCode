class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = INT_MAX;
        int ans = INT_MIN;
        for(int x : prices){
            if(x < leftMin){
                leftMin = x;
            }
            if(ans < x - leftMin){
                ans = x - leftMin;
            }
        }
        return ans;
    }
};