class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int m = (1e9)+7;
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        int numHCuts = hCuts.size(), numVCuts = vCuts.size();
        int maxW = max(vCuts[0], w - vCuts.back());
        for(int i = 0; i < numVCuts-1; i++){
            maxW = max(maxW, vCuts[i + 1] - vCuts[i]);
        }
        int maxH = max(hCuts[0], h - hCuts.back());
        for(int i = 0; i < numHCuts-1; i++){
            maxH = max(maxH, hCuts[i + 1] - hCuts[i]);
        }
        maxW%=m;
        maxH%=m;
        cout << maxW << " " << maxH << endl;
        return ((long long)(maxW%m) * (maxH%m))%m;
    }
};