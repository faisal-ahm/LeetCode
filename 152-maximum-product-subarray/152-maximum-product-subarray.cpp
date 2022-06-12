class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cp = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            cp*= nums[i];
            ans = max(cp, ans);
            if(cp == 0){
                cp = 1;
            }
        }
        cp = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            cp*= nums[i];
            ans = max(cp, ans);
            if(cp == 0){
                cp = 1;
            }            
        }
        return ans;
    }
};