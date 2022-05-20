class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(1,{1});
        for(int i = 1; i < numRows; i++){
            vector<int>currRow(i+1);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    currRow[j] = 1;
                }else{
                    currRow[j] = ans[i-1][j] + ans[i-1][j-1];
                }
            }
            ans.push_back(currRow);
        }
        return ans;
    }
};