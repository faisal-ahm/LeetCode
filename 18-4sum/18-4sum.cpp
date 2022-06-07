class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < n-3; i++){
            if(i!=0 && nums[i-1] == nums[i]){
                continue;
            }
            int target = t - nums[i];
            for(int j = i + 1; j < n - 2; j++){
                if(j!=i+1 && nums[j-1] == nums[j]){
                    continue;
                }
                int target2 = target - nums[j];
                int k = j + 1; int l = n - 1;
                while(k < l){
                    if(nums[k] + nums[l] < target2){
                        k++;
                    }else if(nums[k] + nums[l] > target2){
                        l--;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < l && nums[k+1] == nums[k])k++;
                        while(k < l && nums[l-1] == nums[l])l--;
                        k++;
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};