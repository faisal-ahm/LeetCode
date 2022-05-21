class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, sum = 0, n = nums.size();
        for(int x : nums){
            sum += x;
        }
        
        int currSum = 0, ans = -1;
        for(i = 0; i < n; i++){
            if((sum - currSum - nums[i]) == currSum){
                ans = i;
                break;
            }else{
                currSum += nums[i];
            }
        }
        return ans;
    }
};