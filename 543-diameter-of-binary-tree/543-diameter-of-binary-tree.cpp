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
    pair<int,int>dh(TreeNode*root){
        if(!root){
            return {0,0};
        }
        auto leftAns = dh(root->left);
        auto rightAns = dh(root->right);
        int finHeight = max(leftAns.first, rightAns.first) + 1;
        int finDiamet = max(max(leftAns.second, rightAns.second),leftAns.first + rightAns.first);
        return {finHeight, finDiamet};
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dh(root).second;
    }
};