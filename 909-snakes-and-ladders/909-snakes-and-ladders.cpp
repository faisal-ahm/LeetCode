class Solution {
public:
    pair<int,int> getLoc(int sq, int n){
        int r = (sq-1)/n;
        int c = (sq-1)%n;
        if(r&1) c = n-1-c;
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(),board.end());
        int n = board.size(), dest = n*n;
        vector<bool>vis(dest + 1, false);
        queue<pair<int,int>>q;
        q.push({1,0});
        vis[1] = true;
        while(q.size()){
            int sq = q.front().first, mov = q.front().second;
            q.pop();
            for(int i = 1; i < 7; i++){
                int nsq = sq+i;
                auto loc = getLoc(nsq, n);
                int r = loc.first, c = loc.second;
                if(board[r][c] != -1) nsq = board[r][c];
                if(nsq == dest) return mov+1;
                if(!vis[nsq]){
                    vis[nsq] = true;
                    q.push({nsq, mov+1});
                }
            }
        }
        return -1;
    }
};