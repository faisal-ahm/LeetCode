class Solution {
public:
    void help(vector<int>&nums, vector<int>&path, vector<vector<int>>& ans, vector<bool>&visited){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                help(nums, path, ans, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>path;
        vector<bool>visited(nums.size(), false);
        help(nums, path, ans, visited);
        return ans;
    }
};