class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int counter = 0;
        for(int x : nums){
            if(counter == 0){
                candidate = x;
            }
            if(candidate == x){
                counter++;
            }else{
                counter--;
            }
        }
        return candidate;
    }
};