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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        long largest = LONG_MIN;
        while(q.size()){
            TreeNode* front = q.front();
            q.pop();
            if(!front){
                if(largest != LONG_MIN){
                    ans.push_back(largest);
                }
                if(q.size())q.push(NULL);
                largest = LONG_MIN;
            }else{
                largest = largest > front->val ? largest : front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return ans;
    }
};