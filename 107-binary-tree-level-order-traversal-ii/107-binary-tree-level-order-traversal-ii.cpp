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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>>st;
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        vector<int>level;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            auto front = q.front();
            q.pop();
            if(!front){
                if(level.size()){
                    st.push(level);
                }
                level = {};
                if(!q.empty())q.push(NULL);
            }else{
                level.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};