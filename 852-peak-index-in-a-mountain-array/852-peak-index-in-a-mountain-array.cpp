class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                ans = mid;
                break;
            }else if(arr[mid] > arr[mid-1]){
                start = mid;
            }else if(arr[mid] > arr[mid+1]){
                end = mid;
            }else{
                break;
            }
        }
        return ans;
    }
};