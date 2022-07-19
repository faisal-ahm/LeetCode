class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0, maxCap = 0, n = weights.size();
        for(int weight : weights){
            minCap = max(weight, minCap);
            maxCap += weight;
        }
        
        while(minCap < maxCap){
            int mid = minCap + (maxCap - minCap)/2;
            
            int d = 1, curr = 0;
            for(int i = 0; i < n && d <= days; i++){
                if(curr + weights[i] > mid){
                    curr = weights[i];
                    d++;
                }else{
                    curr+=weights[i];
                }
            }
            
            if(d <= days){
                maxCap = mid;
            }else{
                minCap = mid + 1;
            }
        }
        return minCap;
    }
};