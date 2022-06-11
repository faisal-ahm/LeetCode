/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPeak(MountainArray &a){
        int start = 0, end = a.length()-1;
        while(start < end){
            int mid = (start + end)/2;
            if(a.get(mid) > a.get(mid+1)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }
    int findInMountainArray(int target, MountainArray &a) {
        int peakIndex = getPeak(a);
        //seaarching first half
        int start = 0, end = peakIndex, ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(a.get(mid) > target){
                end = mid - 1;
            }else if(a.get(mid) < target){
                start = mid + 1;
            }else{
                ans = mid;
                break;
            }
        }
        if(ans!=-1){
            return ans;
        }
        start = peakIndex + 1, end = a.length()-1, ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(a.get(mid) < target){
                end = mid - 1;
            }else if(a.get(mid) > target){
                start = mid + 1;
            }else{
                ans = mid;
                break;
            }
        }
        return ans;
    }
};