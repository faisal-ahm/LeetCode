class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums){
	vector<vector<int>> ans;
	int n = nums.size(), p = 1 << n;

	for(int i = 0; i < p; i++){
		vector<int>currSet;
		for(int j = 0; j < n; j++){
			if((i >> j) & 1) currSet.push_back(nums[j]);
		}
		ans.push_back(currSet);
	}
	return ans;
}
};