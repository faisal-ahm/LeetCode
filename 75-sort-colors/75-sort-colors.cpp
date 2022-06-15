class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, c = 0;
        while(c <= j && i < j){
            if(nums[c] == 0){
                nums[c++] = nums[i];
                nums[i++] = 0;
            }else if(nums[c] == 2){
                int temp = nums[j];
                nums[j--] = 2;
                nums[c] = temp;
            }else{
                c++;
            }
        }
    }
};