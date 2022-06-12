class Solution {
public:
    int mySqrt(int x) {
        long long start = 0, end = INT_MAX;
        int ans = -1;
        while(start <= end){
            auto mid = start + (end-start)/2;
            if(mid*mid <= x){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};