// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        int cnt=0;
        int p=n;
        while(n>1){
            if(n%2==0){
                n/=2;
            }
            else if(n%2!=0){
                n-=1;
            }
            cnt++;
        }
        int cnt1=0;
        while(p>1){
            if(p%2==0){
                p/=2;
            }
            else if(p%2!=0){
                p+=1;
            }
            cnt1++;
        }
        return min(cnt,cnt1);
    }
};