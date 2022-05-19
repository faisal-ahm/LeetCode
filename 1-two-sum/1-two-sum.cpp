class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>indices;
    vector<int>ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(indices.find(target - nums[i]) != indices.end()){
            ans = {indices[target - nums[i]], i};
            break;
        }else{
            indices[nums[i]] = i;
        }
    }
    return ans;
}
};