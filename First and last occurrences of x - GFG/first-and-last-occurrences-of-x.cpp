// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x ){
    int s = 0, e = n-1, start = -1, end = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] > x){
            e = mid - 1;
        }else if(arr[mid] < x){
            s = mid + 1;
        }else{
            start = mid;
            if(end == -1){
                end = start;
            }
            e = mid - 1;
        }
    }
    if(start == -1)return {start,end};
    s = end + 1, e = n-1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] > x){
            e = mid - 1;
        }else if(arr[mid] < x){
            s = mid + 1;
        }else{
            end = mid;
            s = mid + 1;
        }
    }
    return {start,end};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends