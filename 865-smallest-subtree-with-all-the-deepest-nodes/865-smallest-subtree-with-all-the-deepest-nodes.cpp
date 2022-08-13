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
    pair<TreeNode*, int> help(TreeNode* root){
        if(!root) return {root, 0};
        pair<TreeNode*, int> left = help(root->left);
        pair<TreeNode*, int> right = help(root->right);
        if(left.second > right.second){
            return {left.first, 1 + left.second};
        }else if(left.second < right.second){
            return {right.first, 1 + right.second};
        }else{
            return {root, 1 + right.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return help(root).first;
    }
};