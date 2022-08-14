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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int cnt = 0;
        long long sum = 0;
        vector<double>ans;
        while(q.size()){
            auto front = q.front();
            q.pop();
            if(!front){
                ans.push_back(sum/(double)cnt);
                if(q.size()) q.push(NULL);
                cnt = 0;
                sum = 0;
            }else{
                cnt++;
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return ans;
    }
};