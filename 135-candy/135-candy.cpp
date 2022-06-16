class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candies(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = 1 + candies[i-1];
            }
            cout << candies[i] << " ";
        }
        cout << endl;
        int ans = 0;
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], 1 + candies[i+1]);
            }
            ans += candies[i];
            cout << candies[i] << " ";
        }
        return ans = ans + candies[n-1];
    }
};