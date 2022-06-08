class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0, lastJump = 0, jumps = 0, i = 0;
    while(lastJump < n - 1){
        maxReach = max(maxReach, i + nums[i]);
        if(i == lastJump){
            lastJump = maxReach;
            jumps++;
        }
        i++;
    }
    return jumps;
}
};