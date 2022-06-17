// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m){
        int maxi = 0;
        vector<int>dp(m+1,0);
        int prevI;
        for(int i = 1; i <= n; i++){
            prevI = dp[0];
            for(int j = 1; j <= m; j++){
                int temp = dp[j];
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + prevI;
                    maxi = max(dp[j], maxi);
                }else{
                    dp[j] = 0;
                }
                prevI = temp;
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends