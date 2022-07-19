class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
    long long sum = 0, n = candies.size();
    for(int i = 0; i < n; i++){
        sum += (long)candies[i];
    }

    long long left = 0;
    long long right = sum/k;
    while(left < right){

        long long mid = (left + right + 1)/2;
        long long numKidsPossible = 0;

        for(int i = 0; i < n && numKidsPossible <= k; i++){
            numKidsPossible += ((long long)candies[i])/mid;

        }
        if(numKidsPossible >= k){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    return left;
}
};