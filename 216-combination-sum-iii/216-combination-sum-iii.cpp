class Solution {
public:
    void help(int k, int i, int sum, int target, vector<int>&comb, vector<vector<int>>& ans){
        if(k == 0 && sum == target){
            ans.push_back(comb);
            return;
        }
        if(i == 10 || sum > target || k <= 0) return;
        comb.push_back(i);
        help(k - 1, i + 1, sum + i, target, comb, ans);
        comb.pop_back();
        help(k, i + 1, sum, target, comb, ans);        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>comb;
        vector<vector<int>>ans;
        help(k, 1, 0, n, comb, ans);
        return ans;
    }
};