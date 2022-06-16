class Solution {
public:
    string countAndSay(int N) {
        if(N == 1){
            return "1";
        }
        string recAns = countAndSay(N-1);
        int n = recAns.size();
        string ans = "";
        for(int i = 0; i < n;){
            int j = i+1;
            while(j < n && recAns[j] == recAns[i]){
                j++;
            }
            int count = j-i;
            ans += to_string(count);
            ans += recAns[i];
            i=j;
        }
        return ans;
    }
    
};