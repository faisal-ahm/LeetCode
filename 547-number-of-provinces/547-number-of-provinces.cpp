class Solution {
public:
    void print(vector<vector<int>>& v){
        for(auto i : v){
            for(int x : i){
                char c = x==1 ? '#' : '.';
                cout << c << " ";
            }
            cout << endl;
        }
        int n = v.size();
        cout << n << endl;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(v[i][j]) cout << i << " " << j << endl;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // print(isConnected);
        // cout << "-----------" << endl;
        int n = isConnected.size();
        queue<int>q;
        vector<bool>vis(n, false);
        int notVis = n;
        int ans = 0;
        while(notVis){
            if(q.empty()){
                ans++;
                int i = 0;
                while(i < n && vis[i]!=0) i++;
                q.push(i);
                vis[i] = true;
                notVis--;
            }else{
                int node = q.front();
                q.pop();
                cout << node <<  " " << notVis << endl;
                for(int i = 0; i < n; i++){
                    if(!vis[i] && isConnected[node][i]){
                        q.push(i);
                        vis[i] = true;
                        notVis--;
                    }
                }
            }
        }
        cout << vis[2] << endl;
        return ans;
    }
};