class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>remIndices;
        remIndices[0] = -1;
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            int rem = sum%k;
            if(remIndices.find(rem) != remIndices.end()){
                if(i - remIndices[rem] > 1){
                    return true;
                }
            }else{
                remIndices[rem] = i;
            }
        }
        return false;
        
        
//         int n = nums.size();
//         for(int i = 0; i < n-1; i++){
//             int sum = nums[i];
//             for(int j = i + 1; j < n; j++){
//                 sum+=nums[j];
//                 if(sum%k == 0){
//                     cout << i <<" " << j << endl;
//                     return true;
//                 }
//             }
//         }
//         return false;
    }
};