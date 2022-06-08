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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        int sum = root->val <= high && root->val >= low ? root->val : 0;
        int right = root->val < high ? rangeSumBST(root->right, max(root->val, low), high) : 0;
        int left = root->val > low ? rangeSumBST(root->left, low, min(root->val, high)) : 0;
        return sum + right + left;
    }
};