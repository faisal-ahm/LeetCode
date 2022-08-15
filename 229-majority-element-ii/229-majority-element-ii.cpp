class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = INT_MIN;
        int c2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int x : nums){
            if(c1 == x){
                cnt1++;
            }else if(c2 == x){
                cnt2++;
            }else if(!cnt1){
                c1 = x;
                cnt1 = 1;
            }else if(!cnt2){
                c2 = x;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        vector<int>ans;
        for(int x : nums){
            if(x == c1) cnt1++;
            else if(c2 == x) cnt2++;
        }
        if(cnt1 > nums.size()/3) ans.push_back(c1);
        if(cnt2 > nums.size()/3) ans.push_back(c2);
        return ans;
    }
};