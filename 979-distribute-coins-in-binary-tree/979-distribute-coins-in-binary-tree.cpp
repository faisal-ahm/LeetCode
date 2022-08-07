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
    int help(TreeNode* root, int& moves){
        if(!root)return 0;
        int left = help(root->left, moves);
        int right = help(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        help(root,moves);
        return moves;
    }
};