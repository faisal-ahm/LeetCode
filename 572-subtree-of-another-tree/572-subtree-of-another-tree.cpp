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
    bool areEqual(TreeNode* s, TreeNode* t) {
    if (s == nullptr || t == nullptr) {
      return s == t;  // both null
    }
    return s->val == t->val && areEqual(s->left, t->left) && areEqual(s->right, t->right);
  }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return root && (areEqual(root, subroot) || isSubtree(root->left, subroot) || isSubtree(root->right, subroot));
    }
};