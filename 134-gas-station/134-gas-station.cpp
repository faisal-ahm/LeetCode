class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, subTotal = 0, start = 0, n = gas.size();
        for(int i = 0; i < n; i++){
            if(subTotal < 0){
                subTotal = 0;
                start = i;
            }
            int difference = gas[i] - cost[i];
            total += difference;
            subTotal += difference;
        }
        return total < 0 ? -1 : start;
    }
};