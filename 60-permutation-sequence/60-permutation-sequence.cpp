class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums(n);
        for(int i = 1; i <= n; i++){
            fact *= i;
            nums[i-1] = i;
        }
        k--;
        string ans = "";
        while(!nums.empty()){
            fact = fact/nums.size();
            char digit = '0' + nums[k/fact];
            ans += digit;
            nums.erase(nums.begin() + k/fact);
            k = k%fact;
        }
        return ans;
    }
};