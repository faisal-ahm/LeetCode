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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> ms;
        queue<TreeNode*> cs;
        bool l2r = true;
        vector<vector<int>>ans;
        vector<int>level;
        if(root) ms.push(root);
        while(ms.size() || cs.size()){
            if(!ms.size()){
                ans.push_back(level);
                level = {};
                while(cs.size()){
                    ms.push(cs.front());
                    cs.pop();
                }
                l2r = !l2r;
            }else{
                auto top = ms.top();
                ms.pop();
                level.push_back(top->val);
                if(l2r){
                    if(top->left) cs.push(top->left);
                    if(top->right) cs.push(top->right);
                }else{
                    if(top->right) cs.push(top->right);
                    if(top->left) cs.push(top->left);
                }
            }
        }
        if(level.size())ans.push_back(level);
        return ans;
    }
};