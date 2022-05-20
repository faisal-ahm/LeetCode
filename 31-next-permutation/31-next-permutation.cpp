class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        if(i>=0){
            int j = n-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            int start = i + 1, end = n-1;
            while(start < end){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
            
        }else{
            int start = 0, end = n-1;
            while(start < end){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
        }
    }
};