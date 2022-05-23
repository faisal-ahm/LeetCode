class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int,int>m;
        m[0] = 1;
        for(int x : nums){
            sum += x;
            int rem = sum % k;
            if(rem < 0) rem += k;
            result += m[rem];
            m[rem]++;
        }
        return result;
    }
};