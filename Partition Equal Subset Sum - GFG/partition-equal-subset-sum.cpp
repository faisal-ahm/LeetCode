// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int N, int arr[],vector<vector<int>>&dp,int sum, int start = 0){
        if(sum == 0){
            return 1;
        }
        if(N == start){
            return 0;
        }
        if(dp[start][sum]!=-1){
            return dp[start][sum];
        }
        int ans;
        if(arr[start] > sum){
            ans = helper(N,arr,dp,sum,start+1);
        }else{
            ans = helper(N, arr,dp,sum-arr[start],start+1) || helper(N,arr,dp, sum, start+1);
        }
        return dp[start][sum] = ans;
    }
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        else{
            vector<vector<int>>dp(N+1,vector<int>((sum/2)+1,-1));
            return helper(N, arr, dp, sum/2);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends