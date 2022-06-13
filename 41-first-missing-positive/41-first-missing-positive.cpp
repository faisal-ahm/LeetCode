class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lastMissing = 1;
        for(int x : nums){
            if(x <= 0)continue;
            if(x>lastMissing){
                break;
            }
            if(x == lastMissing){
                lastMissing++;
            }
        }
        return lastMissing;
    }
};