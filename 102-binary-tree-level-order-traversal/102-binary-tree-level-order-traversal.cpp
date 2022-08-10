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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int>level;
        while(true){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode == NULL){
                if(level.size()!=0){
                    ans.push_back(level);
                }
                level = {};
                if(q.empty()){
                    break;
                }
            }else{
                level.push_back(frontNode->val);
                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right != NULL){
                    q.push(frontNode->right);
                }
                if(q.front() == NULL){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};