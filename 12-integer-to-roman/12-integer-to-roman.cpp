class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while(num){
            if(num >= 900){
                if(num >= 1000){
                    ans += 'M';
                    num-=1000;
                }else{
                    ans += "CM";
                    num -= 900;
                }
            }else if(num >= 400){
                if(num >= 500){
                    ans += 'D';
                    num-= 500;
                }else{
                    ans += "CD";
                    num -= 400;
                }
            }else if(num >= 90){
                if(num >= 100){
                    ans += 'C';
                    num-=100;
                }else{
                    ans += "XC";
                    num -= 90;
                }
            }else if(num >= 40){
                if(num >= 50){
                    ans += 'L';
                    num-= 50;
                }else{
                    ans += "XL";
                    num -= 40;
                }
            }else if(num >= 9){
                if(num >= 10){
                    ans += 'X';
                    num -= 10;
                }else{
                    ans += "IX";
                    num -= 9;
                }
            }else if(num >= 4){
                if(num >= 5){
                    ans += 'V';
                    num -= 5;
                }else{
                    ans += "IV";
                    num -= 4;
                }
            }else{
                ans += 'I';
                num -= 1;
            }
        }
        return ans;
    }
};