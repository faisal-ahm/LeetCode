class Solution {
public:
    void help(int s, vector<int>& subset, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size();
        if(s >= n){
            ans.push_back(subset);
            return;
        }
        //all subsets containing nums[s]
        subset.push_back(nums[s]);
        help(s + 1, subset, ans, nums);
        subset.pop_back();

        //all subsets not containing nums[s];
        while(s+1 < n && nums[s] == nums[s+1]) s++;
        help(s + 1, subset, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;
        help(0, subset, ans, nums);

        return ans;
    }
};