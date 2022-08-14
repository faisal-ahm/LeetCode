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
    pair<TreeNode*, int> getParentDepth(TreeNode*root, int x){
        if(!root) return {NULL, -1};
        if(root->val == x)return {NULL, 0};
        auto ans = getParentDepth(root->left, x);
        if(ans.second != -1){
            if(!ans.first) return {root, 1 + ans.second};
            return {ans.first, 1 + ans.second};
        }
        ans = getParentDepth(root->right,x);
        if(ans.second== -1) return {NULL, -1};
        if(!ans.first) return {root, 1 + ans.second};
        return {ans.first, 1 + ans.second};
    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto forx = getParentDepth(root, x);
        auto fory = getParentDepth(root, y);
        return forx.first != fory.first && forx.second == fory.second;
    }
};