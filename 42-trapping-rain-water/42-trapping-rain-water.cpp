class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        //setting leftMax
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, height[i]);
            leftMax[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            maxi = max(maxi, height[i]);
            rightMax[i] = maxi;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans+=min(leftMax[i], rightMax[i])-height[i];
        }
        return ans;
    }
};