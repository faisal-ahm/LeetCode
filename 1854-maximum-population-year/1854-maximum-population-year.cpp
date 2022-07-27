class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 0;
        vector<int>pop(2051, 0);
        for(auto log : logs){
            pop[log[0]]++;
            pop[log[1]]--;
        }
        for(int i = 1950; i<2050; i++){
            pop[i] += pop[i-1];
            ans = pop[i] > pop[ans] ? i : ans;
        }
        return ans;
    }
};