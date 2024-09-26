// https://leetcode.com/problems/reverse-integer

#include<bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
        int n=abs(x);
        int p=0;
        while(n>0){
            int c=n%10;
            p*=10;
            p+=c;
            n/=10;
        }
        if(x>=0){
        if(x>2147483647){
            return 0;
        }
        return p;}
        else{
            if(x<-2147483647){
                return 0;
            }
            return -p;
        }
        }
};