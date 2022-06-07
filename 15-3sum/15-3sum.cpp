class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < n-2; i++){
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = nums[i] * -1;
            int j = i + 1, k = n-1;
            while(j < k){
                if(nums[j] + nums[k] < target){
                    j++;
                }else if(nums[j] + nums[k] > target){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j + 1] == nums[j])j++;
                    while(j < k && nums[k - 1] == nums[k])k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};