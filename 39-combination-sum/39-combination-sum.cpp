class Solution {
public:
    
    void helper(vector<int>& candidates, int target, int currSum, int currIndex, vector<int>&currComb, vector<vector<int>>&ans){
        if(currSum > target || currIndex >= candidates.size()){
            return;
        }
        if(currSum == target){
            ans.push_back(currComb);
            return;
        }
        currComb.push_back(candidates[currIndex]);
        helper(candidates, target, currSum + candidates[currIndex], currIndex, currComb, ans);
        currComb.pop_back();
        helper(candidates,target,currSum,currIndex + 1, currComb, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>currComb;
        helper(candidates,target, 0,0,currComb,ans);
        return ans;
    }
};