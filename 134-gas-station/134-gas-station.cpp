class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int difference = 0, total = 0, ans = 0, subtotal = 0;
        for(int i = 0; i < n; i++){
            if(subtotal < 0){
                subtotal = 0;
                ans = i;
            }
            difference = gas[i] - cost[i];
            total += difference;
            subtotal += difference;
        }
        return total < 0 ? -1 : ans;
    }
};