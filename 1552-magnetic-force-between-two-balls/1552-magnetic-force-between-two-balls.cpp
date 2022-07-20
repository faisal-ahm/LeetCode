class Solution {
public:
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0, right = position.back() - position.front();
        while(left < right){
            int mid = right - (right - left)/2;
            int ans = 1, curr = position[0];
            for(int i = 1; i < position.size(); i++){
                if(position[i] - curr >= mid){
                    ans++;
                    curr = position[i];
                }
            }
            if(ans >= m){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};