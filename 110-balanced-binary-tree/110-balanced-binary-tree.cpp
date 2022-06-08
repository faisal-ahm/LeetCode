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
    pair<int,bool>helper(TreeNode*root){
        if(!root){
            return {0, true};
        }
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        int finalHeight = max(leftAns.first, rightAns.first) + 1;
        return {finalHeight, leftAns.second && rightAns.second && abs(leftAns.first - rightAns.first) <= 1};
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root).second;
    }
};