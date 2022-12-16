class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = INT_MAX, ans = INT_MIN;
        
        for(int x : prices){
            leftMin = min(leftMin, x);
            ans = max(ans, x-leftMin);
        }
        
        return ans;
    }
};