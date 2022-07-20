class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while(left < right){
            int mid = left + (right - left)/2, currOps = 0;
            for(int x : nums){
                //some operation to get currOps
                currOps += (x-1)/mid;
            }
            if(currOps > maxOperations){
                left = mid + 1;
                
            }else{
                right = mid;
            }
        }
        return left;
    }
};