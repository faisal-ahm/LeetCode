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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val)return root;
        if(root->val < val)return searchBST(root->right, val);
        return searchBST(root->left, val);
        auto temp = root;
        while(true){
            if(!temp || temp->val == val){
                return temp;
            }
            if(temp->val > val){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
    }
};