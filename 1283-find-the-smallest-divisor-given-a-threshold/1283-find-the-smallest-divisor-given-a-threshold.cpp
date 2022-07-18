class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, ans;
        
        while(left < right){
            int mid = left + (right - left)/2;
            int total = 0;
            for(int x : nums){
                total += (mid + x - 1)/mid;
            }
            if(total > threshold){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};