class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>op(n);
        int l = 0, r = n-1, i = n-1;
        while(i >= 0){
            int rightSqr = nums[r] * nums[r];
            int leftSqr = nums[l] * nums[l];
            if(rightSqr > leftSqr){
                op[i] = rightSqr;
                r--;
            }else{
                op[i] = leftSqr;
                l++;
            }
            i--;
        }
        return op;
    }
};