/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void help(TreeNode* root, vector<int>& path, vector<vector<int>>& ans, int targetSum){
        if(!root) return;
        
        if(!(root->left) && !(root->right)){
            if(targetSum == root->val){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        if(root->left)help(root->left, path, ans, targetSum - root->val);
        if(root->right)help(root->right, path, ans, targetSum - root->val);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        help(root, path, ans, targetSum);
        return ans;
    }
};