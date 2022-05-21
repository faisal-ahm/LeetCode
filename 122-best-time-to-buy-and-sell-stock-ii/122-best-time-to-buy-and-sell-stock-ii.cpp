class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();
        for(int i = 0; i < n-1; i++){
            int j = i + 1;
            while(j < n && prices[j-1] <= prices[j]){
                j++;
            }
            profit += prices[j-1] - prices[i];
            i = j-1;
        }
        return profit;
    }
};