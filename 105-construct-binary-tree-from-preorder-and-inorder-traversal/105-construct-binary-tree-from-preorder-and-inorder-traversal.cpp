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
    TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd){
        if(inStart == inEnd) return new TreeNode(preorder[preStart]);
        if(inStart > inEnd) return NULL;
        
        int n = inEnd - inStart + 1;
        
        TreeNode*root = new TreeNode(preorder[preStart]);
        
        int leftLen = 0;
        while(inorder[inStart + leftLen] != root->val){
            leftLen++;
        }
        root->left = helper(inorder, preorder, inStart, inStart + leftLen - 1, preStart + 1, preStart + leftLen - 1);
        int rightLen = n - leftLen - 1;
        root->right = helper(inorder, preorder,inStart + leftLen + 1, inEnd, preStart + leftLen + 1, preEnd);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    int n = inorder.size();
    return helper(inorder, preorder, 0, n-1, 0, n-1);
    }
};