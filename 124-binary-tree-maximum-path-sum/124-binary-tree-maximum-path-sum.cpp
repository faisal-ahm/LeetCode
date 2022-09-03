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
    int hlp(TreeNode* root, int& res){
        if(!root) return NULL;
        int l = hlp(root->left, res);
        int r = hlp(root->right, res);
        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        hlp(root, ans);
        return ans;
    }
};