// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  #define ll long long
    long long int count(int S[], int m, int n) {
        vector<ll>dp(n+1,0);
        dp[0] = 1;
        for(ll i = 0; i < m; i++){
            for(ll j = 1; j <= n; j++){
                if(S[i] <= j)dp[j] += dp[j-S[i]];
            }
        }
        return dp[n];
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends