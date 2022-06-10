class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0; 
        int end = n-1;
        int sA = -1, eA = -1;
        //finding start index
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                sA = mid;
                eA = eA == -1 ? sA : eA;
                end = mid-1;
            }
        }
        if(sA == -1){
            return {-1,-1};
        }
        start = eA + 1, end = n-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                eA = mid;
                start = mid+1;
            }
        }
        return {sA, eA};
    }
};