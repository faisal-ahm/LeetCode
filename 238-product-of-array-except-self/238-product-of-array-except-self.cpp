class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int n = nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] * pre[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suf[i] = nums[i] * suf[i+1];
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            int preProd = i == 0 ? 1 : pre[i-1];
            int sufProd = i == n-1 ? 1 : suf[i+1];
            ans[i] = preProd * sufProd;
        }
        return ans;
    }
};