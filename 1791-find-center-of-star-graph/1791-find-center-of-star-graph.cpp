class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int numEdges = edges.size();
        if(numEdges == 1){
            return edges[0][0];
        }
        int a = edges[0][0],b = edges[0][1],c = edges[1][0],d = edges[1][1];
        if(a == c || a== d){
            return a;
        }else{
            return b;
        }
        
        
    }
};