class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        bool isFirstRowZero = false;
        for(int i = 0; i < numCols; i++){
            if(matrix[0][i] == 0){
                isFirstRowZero = true;
                break;
            }
        }
        
        //setting rows 0
        for(int i = 1; i < numRows; i++){
            bool isCurr0 = false;
            for(int j = 0; j < numCols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    isCurr0 = true;
                } 
            }
            if(isCurr0){
                for(int j = 0; j < numCols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //setting cols 0
        for(int i = 0; i < numCols; i++){
            if(matrix[0][i] == 0){
                for(int j = 1; j < numRows; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        //setting first row 0;
        if (isFirstRowZero){
            for(int i = 0; i < numCols; i++){
                matrix[0][i] = 0;
            }
        }
    }
};