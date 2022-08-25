class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<int>& path, vector<vector<int>>&ans, int i){
        int n = g.size();
        path.push_back(i);
        if(i == (n-1)){
            ans.push_back(path);
        }else{
            for(auto x : g[i]) {
                dfs(g, path, ans, x);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(g, path, paths, 0);
        return paths;
    }
};