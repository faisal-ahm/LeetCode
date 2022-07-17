class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), left = 1, right = 1e9;
        
        while(left < right){
            int mid = left + (right - left)/2;
            int total = 0;
            for(int pile : piles){
                total += (pile + mid - 1)/mid;
            }
            if(total > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
        
    }
};