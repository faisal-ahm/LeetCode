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
    TreeNode* helper(vector<int>& preorder, int s, int e){
        if(s > e)return NULL;
        if(s == e)return new TreeNode(preorder[s]);
        auto root = new TreeNode(preorder[s]);
        if(preorder[s + 1] > root->val){
            root->right = helper(preorder, s + 1, e);
            return root;
        }        
        int leftStart = s + 1;
        int leftEnd = leftStart;
        while(leftEnd <= e && preorder[leftEnd] < root->val){
            leftEnd++;
        }
        leftEnd--;
        root->left = helper(preorder, leftStart, leftEnd);
        root->right = helper(preorder, leftEnd + 1, e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};