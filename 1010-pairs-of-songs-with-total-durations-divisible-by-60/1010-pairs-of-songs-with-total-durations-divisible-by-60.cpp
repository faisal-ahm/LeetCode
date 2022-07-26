class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int>m;
        for(int x : time){
            int r = x % 60;
            ans += m[(60 - r)%60];
            m[r]++;
        }
        return ans;
    }
};