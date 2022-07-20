class Solution {
public:

long long minimumTime(vector<int>& time, int totalTrips) {
    long long int left = 0, right  = 1e14, ans = 0;
    while(left < right){
        long long int mid =left + (right-left)/2;
        cout << left << " " << mid << " " << right;
        long long int tot = 0;
        for(int i = 0; i < time.size() && tot <= totalTrips; i++){
            long long int val = time[i];
            tot += mid/val;
        }
        cout << " " << tot << endl;
        if(tot >= totalTrips){
            ans = mid;
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}
};