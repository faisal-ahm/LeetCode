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
    pair<pair<pair<int,int>, bool>, int> help(TreeNode* root, int& ans){
        if(!root) return{{{INT_MIN, INT_MAX}, true}, 0};
        
        auto left = help(root->left, ans);
        auto right = help(root->right, ans);
        int lMax = left.first.first.first;
        int lMin = left.first.first.second;
        int rMax = right.first.first.first;
        int rMin = right.first.first.second;
        bool lBool = left.first.second, rBool = right.first.second;
        int lSum = left.second, rSum = right.second;
        
        
        bool aBool;
        int aMin = min(root->val, lMin), aMax = max(root->val, rMax), aSum;
        if(lBool && rBool && (lMax < root->val) && (rMin > root->val)){
            aBool = true;
            aSum = root->val + lSum + rSum;
        }else{
            aBool = false;
            aSum = max(lSum, rSum);
        }
        ans = max(ans, aSum);
        return {{{aMax, aMin}, aBool}, aSum}; 
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }
};