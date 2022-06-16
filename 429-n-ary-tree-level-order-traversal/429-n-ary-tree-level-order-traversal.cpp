/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>row;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front){
                row.push_back(front->val);
                for(auto child : front->children){
                    q.push(child);
                }
            }else{
                ans.push_back(row);
                row = {};
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};