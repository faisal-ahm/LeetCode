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
        long long a = 1;
        long long b = 2;
        long long c = 4;
        long long d;
        for(int i = 4; i <= n; i++){
            d = (a%M + b%M + c%M)%M;
            a= b;
            b = c;
            c = d;
        }
        return d;
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