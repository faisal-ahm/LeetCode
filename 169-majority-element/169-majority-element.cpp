class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>freq;
        for(int x : nums){
            freq[x]++;
            if(freq[x] > n/2){
                ans = x;
                break;
            }
        }
        return ans;
    }
};