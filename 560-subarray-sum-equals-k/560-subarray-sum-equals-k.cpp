class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int>m = {{0,1}};
        for(int x : nums){
            sum += x;
            count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};