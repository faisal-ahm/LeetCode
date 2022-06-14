class Solution {
public:
    
void dfs(int s, int& cnt, vector<vector<int>>& adj, vector<bool>& vis){
    vis[s] = true;
    cnt++;
    for(int x : adj[s]){
        if(!vis[x]){
            dfs(x, cnt, adj, vis);
        }
    }
}

bool aCoversb(vector<int>&a, vector<int>&b){
    int x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1]; long long r1 = a[2];
    long long xComp = (x1-x2), yComp = (y1-y2);
    long long distanceSquared = (xComp)*(xComp) + (yComp)*(yComp);
    return distanceSquared <= (r1*r1) ;
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    //generating adjacency matrix
    vector<vector<int>>adj(n);
    for(int i = 0; i < n; i++){
        vector<int>row;
        for(int j = 0; j < n; j++){
            if(i!=j){
                if(aCoversb(bombs[i], bombs[j])){
                    adj[i].push_back(j);
                }
            }
        }
    }

    //adjacency graph generated
    vector<bool> visited(n,false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        dfs(i, cnt, adj, visited);
        ans = max(cnt, ans);
        fill(visited.begin(),visited.end(), false);
    }
    return ans;
}
};