class Solution {
public:
    int getPeak(vector<int>&nums){
        int start = 0, end = nums.size()-1;
        if(nums[end] > nums[start]){
            return end;
        }
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[mid] > nums[start]){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return start;
    }
    int search(vector<int>& nums, int target) {
        int pivot = getPeak(nums);
        int start = 0, end = pivot;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                return mid;
            }
        }
        start = pivot + 1;
        end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};