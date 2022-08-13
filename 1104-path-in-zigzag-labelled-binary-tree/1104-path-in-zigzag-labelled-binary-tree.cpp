class Solution {
public:
    
    void help(vector<int>&ans, int label){
        if(label == 1){
            ans.push_back(1);
            return;
        }
        int n = log2(label) + 1;
        int minPar = 1 << (n-2);
        int maxPar = (1 << (n-1))-1;
        int parent = minPar + maxPar - (label >> 1);//finding parent
        help(ans, parent);
        ans.push_back(label);
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        help(ans, label);
        return ans;
    }
};