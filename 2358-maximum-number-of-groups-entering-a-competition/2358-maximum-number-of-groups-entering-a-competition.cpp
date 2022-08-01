class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int sum = 0, n = grades.size(), i = 0;
        while(sum <= n){
            sum += i++;
        }
        return i-2;
    }
};