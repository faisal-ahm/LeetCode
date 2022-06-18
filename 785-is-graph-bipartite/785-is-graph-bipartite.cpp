class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<pair<bool,bool>>vis(n, {false, false});
        for(int i = 0; i < n; i++){
            if(vis[i].first){
                continue;
            }
            queue<int>q;
            q.push(i);
            vis[i] = {true,true};
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int s : graph[front]){
                    if(!vis[s].first){
                        q.push(s);
                        vis[s] = {true, !vis[front].second};
                    }else if(vis[s].second == vis[front].second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};