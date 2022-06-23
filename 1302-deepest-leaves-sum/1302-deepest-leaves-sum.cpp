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
    pair<int,int> helper(TreeNode* root){
        if(!root)return {0,0};
        if(!root->left && !root->right)return {1,root->val};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.first == right.first){
            return {1 + left.first, left.second + right.second};
        }else if(left.first < right.first){
            return {1 + right.first, right.second};
        }else{
            return {1 + left.first, left.second};
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        return helper(root).second;
    }
};