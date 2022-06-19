// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int M = 1e9 + 7;
    long long countWays(int n){
        //1 1, 2 2, 3 : 1 + 2 + 1
        if(n == 1 || n == 2){
            return n;
        }
        if(n == 3){
            return 4;
        }
        vector<long long>dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= n; i++){
            dp[i] = (dp[i-1]%M + dp[i - 2]%M + dp[i-3]%M)%M;
        }
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends