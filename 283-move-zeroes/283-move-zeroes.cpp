class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), high = 0, low = 0;
        while(high < n){
            if(nums[high]){
                swap(nums[high],nums[low]);
                low++;
            }
            high++;
        }
    }
};