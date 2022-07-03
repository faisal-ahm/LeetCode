class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(), sat.end());
        int sum = 0;
        int i = n-1;
        while(i >= 0){
            sum+= sat[i];
            if(sum < 0) break;
            i--;
        }
        i++;
        int time = 1;
        int ans = 0;
        while(i < n){
            ans += sat[i++] * time++;
        }
        return ans;
    }
};