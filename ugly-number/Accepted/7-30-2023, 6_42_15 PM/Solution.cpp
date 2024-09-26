// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isUgly(int n) {
        if(n==0){
            return false;
        }
        else if(n==1){
            return true;
        }
        else{
            while(n%2==0){
                n/=2;
            }
            while(n%3==0){
                n/=3;
            }
            while(n%5==0){
                n/=5;
            }
            if(n==1){
                return true;
            }
            else{
                return false;
            }
        }

    }
};