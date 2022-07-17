class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1, j = n, ans;
        while(i <= j){
            long mid = i + (j - i)/2;
            long mul =  mid * (mid + 1)/2;
            if(mul <= n){
                i = mid + 1;
                ans = mid;
            }else{
                j = mid - 1;
            }
        }
        return ans;
    }
};