class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>&ans, int start = 0){
        int n = nums.size();
        if(start == n){
            ans = {{}};
            return;
        }
        helper(nums,ans,start + 1);
        int prevSize = ans.size();
        for(int i = 0; i < prevSize; i++){
            vector<int>row = {nums[start]};
            for(int x : ans[i]){
                row.push_back(x);
            }
            ans.push_back(row);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans);
        return ans;
    }
};