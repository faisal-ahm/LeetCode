class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0, n = nums.size();
        for(int x : nums){
            l = max(l, x);
            r += x;
        }
        
        if(l==0)return 0;
        
        while(l < r){
            int mid = l + (r - l)/2, curr = 0, numPartitions = 1;
            for(int i = 0; i < n && numPartitions <= m; i++){
                if(curr + nums[i] > mid){
                    curr = 0;
                    numPartitions++;
                }
                curr+=nums[i];
            }
            if(numPartitions > m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};