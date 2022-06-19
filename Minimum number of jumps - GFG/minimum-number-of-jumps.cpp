// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int a[], int n){
        int lastJump = 0, i = 0, maxReach = 0, ans = 0;
        if(a[0] == 0 && n > 1)return -1;
        while(lastJump < n - 1){
            maxReach = max(maxReach, i + a[i]);
            if(i == lastJump){
                int temp = lastJump;
                lastJump = maxReach;
                if(lastJump <= temp){
                    return -1;
                }
                ans++;
            }
            i++;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends