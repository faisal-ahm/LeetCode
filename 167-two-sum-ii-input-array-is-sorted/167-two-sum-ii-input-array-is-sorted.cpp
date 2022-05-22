class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int start = 0, end = n-1;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ans = {start + 1, end + 1};
                break;
            }else if(numbers[start] + numbers[end] > target){
                end--;
            }else{
                start++;
            }
        }
        return ans;
    }
};