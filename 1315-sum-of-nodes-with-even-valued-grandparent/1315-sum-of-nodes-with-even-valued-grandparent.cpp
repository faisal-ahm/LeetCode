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
    int getSum(TreeNode* root, int depth = 0){
        if(root == NULL) return 0;
        if(depth == 2) return root->val;
        return getSum(root->left, depth + 1) + getSum(root->right, depth + 1);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        int rootSum = root->val&1 ? 0 : getSum(root);
        int leftSum = sumEvenGrandparent(root->left);
        int rightSum = sumEvenGrandparent(root->right);
        return rootSum + leftSum + rightSum;
    }
};