class Solution {
public:
    void help(vector<int>& candidates, int target, int i, int sum, vector<int>& combs, vector<vector<int>>&ans){
        if(sum == target){
            ans.push_back(combs);
            return;
        }
        int n = candidates.size();
        if(i == n || sum > target)return;
        combs.push_back(candidates[i]);
        help(candidates, target, i + 1, sum + candidates[i], combs, ans);
        int j = i + 1;
        while(j < n && candidates[j-1] == candidates[j])j++;
        combs.pop_back();
        help(candidates, target, j, sum, combs, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>comb;
        vector<vector<int>>ans;
        help(candidates, target, 0, 0, comb, ans);
        return ans;
    }
};