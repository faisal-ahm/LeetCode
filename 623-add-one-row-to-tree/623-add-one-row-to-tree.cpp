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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        if(depth == 2){
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
            root->left = new TreeNode(val, leftTemp, nullptr);
            root->right = new TreeNode(val, nullptr, rightTemp);
            return root;
        }
        root->left = addOneRow(root->left, val, depth - 1);
        root->right = addOneRow(root->right, val, depth-1);
        return root;
    }
};