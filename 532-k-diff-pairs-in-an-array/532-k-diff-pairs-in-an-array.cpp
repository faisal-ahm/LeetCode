class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int& x : nums){
            m[x]++;
        }
        int count = 0;
        if(k == 0){
            for(auto& i : m){
                if(i.second > 1)count++;
            }
            return count;
        }
        for(auto& i : m){
            if(m[i.first] == 0)continue;
            m[i.first]--;
            if(m.find(k + i.first) != m.end() && m[k + i.first] > 0){
                count++;
            }
            if(m.find(i.first - k) != m.end() && m[i.first - k] > 0){
                count++;
            }
            m[i.first] = 0;
        }
        return count;
    }
};