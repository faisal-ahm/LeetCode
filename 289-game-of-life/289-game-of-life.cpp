class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
    /*
    current state(1){
        if(LiveNeighbours == 2 or 3){
            tom = live;
        }else{
            tom = dead;
        }
    }
    current state(0){
        if(LiveNeighbours == 3){
            nextState = 1;
        }
    }
    */
    int numRows = b.size();
    int numCols = b[0].size();
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            int liveCount = 0;
            int NW = j == 0 || i == 0 ? 0 : (b[i-1][j-1] >= 1 ? 1 : 0);
            int SE = j == numCols-1 || i == numRows-1 ? 0 : b[i+1][j+1];
            int NE = j == numCols-1 || i == 0 ? 0 : (b[i-1][j+1] >= 1 ? 1 : 0);
            int SW = j == 0 || i == numRows-1 ? 0 : b[i+1][j-1];
            int N = i == 0? 0 : (b[i-1][j] >= 1 ? 1 : 0);
            int S = i == numRows-1? 0 : b[i+1][j];
            int E = j == numCols-1? 0 : b[i][j+1];
            int W = j == 0? 0 : (b[i][j-1] >= 1 ? 1 : 0);
            liveCount = NW + N + NE + SW + S + SE + E + W;
                
            if(b[i][j] == 0){
                if(liveCount != 3){
                    b[i][j] = -1;
                }
            }else{
                if(liveCount != 2 && liveCount != 3){
                    b[i][j] = 2;
                }
            }
        }
    }
        
    //finally changing  states
    for(auto & rows : b){
        for(auto & x : rows){
            if(x == 0 || x == 1){
                x = 1;
            }else{
                x = 0;
            }
        }
    }
}
};