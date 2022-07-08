class Solution {
public:
    
    int help(vector<int>& nums, int s, int e){
        if(e < s) return 0;
        int m = nums.size()-1;
        
        int b = 0, a = nums[e], c;
        
        for(int i = e-1; i >= s; i--){
            c = max(nums[i] + b, a);
            b = a;
            a = c;
        }
        return a;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        return n == 1 ? nums[0] : max(help(nums, 0, n-2), help(nums, 1, n-1));
    }
};