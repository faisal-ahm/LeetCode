class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex + 1,0);
        for(int i = 0; i <= rowIndex; i++){
            for(int j = i; j >= 0; j--){
                if(j == 0 || j == i){
                    ans[j] = 1;
                }else{
                    ans[j] = ans[j] + ans[j-1];
                }
            }
        }
        return ans;
    }
};