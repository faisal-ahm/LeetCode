class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int x : nums){
            if(!x){
                zeroCount++;
            }
        }
        int i = 0;
        for(int x : nums){
            if(x){
                nums[i] = x;
                i++;
            }
        }
        while(i < nums.size()){
            nums[i++] = 0;
        }
        
    }
};