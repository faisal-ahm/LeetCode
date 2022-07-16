class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        while(i < j){
            int mid = i + (j-i)/2;
            if((mid%2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid-1])){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        return nums[i];
    }
};