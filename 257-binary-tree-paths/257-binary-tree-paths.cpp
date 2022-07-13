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
    void help(TreeNode* root, string path, vector<string>&paths){
        path += to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path);
            return;
        }
        path += "->";
        if(root->left) help(root->left, path, paths);
        if(root->right) help(root->right, path, paths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = "";
        help(root, path, ans);
        return ans;
    }
};