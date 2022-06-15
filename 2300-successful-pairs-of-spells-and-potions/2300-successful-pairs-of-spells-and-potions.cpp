class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans(n, 0);
        for(int i = 0; i < n; i++){
            int smallestIndex = m;
            //finding index
            int start = 0, end = m-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                long long testMul = (long long)potions[mid] * (long long)spells[i];
                if(testMul >= success){
                    end = mid-1;
                    smallestIndex = mid;
                }else{
                    start = mid + 1;
                }
            }
            ans[i] = m-smallestIndex;
        }
        return ans;
    }
};