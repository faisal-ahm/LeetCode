class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char x) {
        int n = letters.size();
        if(x >= letters[n-1]){
            return letters[0];
        }
    int start = 0, end = n-1;
    int ans = -1;
    while(start <= end){
        int mid = (start + end)/2;
        if(letters[mid] <= x){
            start = mid + 1;
        }else{
            ans = mid;
            end = mid-1;
        }
    }
    return letters[ans];
    }
};