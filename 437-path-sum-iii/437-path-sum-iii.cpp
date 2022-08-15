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
    int ans = 0;
    void help(TreeNode* root, long int t){
        if(!root) return;
        if(root->val == t) ans++;
        help(root->left, t-root->val);
        help(root->right, t-root->val);
    }
    int pathSum(TreeNode* root, int t) {
        if(root){
            help(root, t);
            pathSum(root->left, t);
            pathSum(root->right, t);
        }
        return ans;
    }
};