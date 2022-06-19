// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int M =1000000007;
    #define lli long long int
    long long int nthFibonacci(long long int n){
        if(n == 0 ||n== 1){
            return 1;
        }
        lli a = 1,b =1;
        for(int i = 2; i < n; i++){
            lli c = (a + b)%M;
            a = b;
            b = c;
        }
        return b;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends