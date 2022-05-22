class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        for(int i = 0; i < n - 2; i++){
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int low = i + 1, high = n-1;
            int target = 0 - nums[i];
            while(low < high){
                if(nums[low] + nums[high] == target){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low + 1] == nums[low])low++;
                    while(low < high && nums[high - 1] == nums[high])high--;
                    low++;
                    high--;
                }else if(nums[low] + nums[high] < target){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return ans;
    }
};