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
    pair<TreeNode*, TreeNode*> help(TreeNode* root){
        if(!root || (!root->left && !root->right))return {root,root};
        
        auto leftAns = help(root->left);
        auto rightAns = help(root->right);
        
        root->left = NULL;
        if(!rightAns.first){
            root->right = leftAns.first;
            return {root, leftAns.second};
        }
        
        if(leftAns.first){
            root->right = leftAns.first;
            if(!leftAns.second){
                cout << "not left second;";
            }
            leftAns.second->right = rightAns.first;
        }else{
            root->right = rightAns.first;   
        }
        
        return {root, rightAns.second};
    }
    void flatten(TreeNode* root) {
        root = help(root).first;
    }
};