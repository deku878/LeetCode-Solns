// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        int cnt=0;
        while(n>1){
            if(n%2==0){
                n/=2;
            }
            else if(n%2!=0){
                n-=1;
            }
            cnt++;
        }
        return cnt;
    }
};