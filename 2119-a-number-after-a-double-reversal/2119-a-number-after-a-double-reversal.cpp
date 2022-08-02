class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(!(num%10)) return !num;
        return true;
    }
};