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
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        auto left = root->left;
        auto right = root->right;
        root->left = NULL;
        root->right = NULL;
        flatten(left);
        flatten(right);
        root->right = left;
        auto temp = root;
        while(temp->right){
            temp = temp->right;
        }
        temp->right = right;
        
    }
};