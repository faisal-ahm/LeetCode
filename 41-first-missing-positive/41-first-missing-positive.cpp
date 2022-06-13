class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        for(int x : nums){
            s.insert(x);
        }
        int n = nums.size();
        int i = 1;
        for(i; i <= n ; i++){
            if(s.find(i) == s.end()){
                break;
            }
        }
        return i;
    }
};