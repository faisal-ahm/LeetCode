class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0 || x == 1) return 1.0;
        if(x == -1) return n%2 ? -1 : 1;
        if(n < 0) return 1/myPow(x, -1 * n);
        return (n%2) ? x * myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};