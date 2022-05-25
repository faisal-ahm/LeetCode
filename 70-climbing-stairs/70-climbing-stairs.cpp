class Solution {
public:
    
    
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int i1 = 1;
        int i2 = 2;
        int ans;
        for(int i = 3; i <= n; i++){
            ans = i1 + i2;
            i1 = i2;
            i2 = ans;
        }
        return ans;
    }
};