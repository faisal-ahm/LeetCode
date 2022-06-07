class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int minDiff = INT_MAX;
    int sum;
    int n = nums.size();
        sort(nums.begin(),nums.end());
    for(int i = 0; i < n-2; i++){
        if(i!=0 && nums[i-1] == nums[i]){
            continue;
        }
        int t = target - nums[i];
        int high = n-1;
        int low = i + 1;
        while(low < high){
            if(minDiff > abs(nums[low] + nums[high] + nums[i] - target)){
                sum = nums[low] + nums[high] + nums[i];
                cout << sum << " ";
                minDiff = abs(nums[low] + nums[high] + nums[i] - target);
            }
            if(nums[low] + nums[high] < t){
                low++;
            }else if(nums[low] + nums[high] > t){
                high--;
            }else{
                return target;
            }
        }
    }
        cout << endl;
    return sum;
}
};