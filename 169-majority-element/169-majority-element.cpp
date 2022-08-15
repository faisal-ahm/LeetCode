class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int cnt = 0;
        for(int x : nums){
            if(!cnt) candidate = x;
            if(candidate == x) cnt++;
            else cnt--;
        }
        return candidate;
    }
};