class Solution {
public:
    void printVec(vector<int>& v){
        cout << "[";
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            if(i != v.size()-1) cout << ",";
        }
        cout << "]" << endl;
    }
    int lengthOfLIS(vector<int>& arr) {
        vector<int> sub;
        for (int i = 0; i < arr.size(); ++i) {
            int x = arr[i];
            if (sub.empty() || sub[sub.size() - 1] <= x) { // Append to LIS if new element is >= last element in LIS
                sub.push_back(x);
            } else {
                int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); // Find the index of the smallest number > x
                sub[idx] = x; // Replace that number with x
            }
        }
        return sub.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for(int i = 0; i < k; i++){
            vector<int>v;
            for(int j = i; j < n; j+=k){
                v.push_back(arr[j]);
            }
            int lis = lengthOfLIS(v);
            
            ans += v.size() - lis;
        }
        return ans;
    }
};