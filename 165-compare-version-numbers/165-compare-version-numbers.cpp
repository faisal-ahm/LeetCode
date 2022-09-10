class Solution {
public:
    int help(string& v1, string& v2, int& s1, int& s2){
        int n1 = v1.size(), n2 = v2.size();
        while(s1 < n1 && v1[s1] == '0')s1++;
        while(s2 < n2 && v2[s2] == '0')s2++;
        int num1 = 0;
        int num2 = 0;
        while(s1 < n1 && v1[s1] != '.'){
            num1*=10;
            num1 += (v1[s1++] - '0');
        }
        while(s2 < n2 && v2[s2] != '.'){
            num2*=10;
            num2 += (v2[s2++] - '0');
        }
        if(num1 < num2) return -1;
        if(num2 < num1) return 1;
        return 0;
    }
    
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            int ans = help(v1, v2, i, j);
            if(ans) return ans;
            i++;
            j++;
        }
        while(i < n1){
            int ans = help(v1, v2, i, j);
            if(ans) return ans;
            i++;
        }
        while(j < n2){
            int ans = help(v1, v2, i, j);
            if(ans) return ans;
            j++;
        }
        return 0;
    }
};