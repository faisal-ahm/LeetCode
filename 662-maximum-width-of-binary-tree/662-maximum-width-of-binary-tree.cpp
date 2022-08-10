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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        int ans = 1;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        
        while(q.size()){
            int cnt = q.size();
            int start = q.front().second, end = q.back().second;
            
            ans = max(ans, end - start + 1);
            
            for(int i = 0; i < cnt; i++){
                auto p = q.front();
                q.pop();
                
                int idx = p.second - start;
                
                auto node = p.first;
                
                if(node->left) q.push({node->left, (long long)(idx << 1) + 1});
                if(node->right) q.push({node->right, (long long)(idx << 1) + 2});
            }
        }
        return ans;
    }
};