class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size(), l = 0, r = n-1;
        int ans = INT_MIN;
        while(l < r){
            ans = max(ans, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]){
                l++;
            }else if(height[l] > height[r]){
                r--;
            }else{
                l++;
                r--;
            }
        }
        return ans;
    }
};