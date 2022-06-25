// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if(n <= 2){
	        return max(arr[0], arr[n-1]);
	    }
	    int a = arr[0];
	    int b = max(arr[1], arr[0]);
	    
	    for(int i = 3; i <= n; i++){
	        int inc = arr[i-1] + (i <=2 ? 0 : a);
	        int nInc = b;
	        int c = max(inc, nInc);
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends