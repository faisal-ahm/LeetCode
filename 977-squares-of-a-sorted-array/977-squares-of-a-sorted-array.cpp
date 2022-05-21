class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>op(nums.size());
        for(int i = 0; i < nums.size(); i++){
            op[i] = nums[i] * nums[i];
        }
        sort(op.begin(), op.end());
        return op;
    }
};