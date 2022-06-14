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
    int goodNodes(TreeNode* root, int maxi = INT_MIN) {
        if(!root){
            return 0;
        }
        if(root->val >= maxi){
            return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
        }else{
            return goodNodes(root->left, maxi) + goodNodes(root->right, maxi);
        }
    }
};