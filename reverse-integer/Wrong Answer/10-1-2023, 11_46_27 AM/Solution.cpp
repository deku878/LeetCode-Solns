// https://leetcode.com/problems/reverse-integer

#include<bits/stdc++.h>
class Solution {
public:
    long long int reverse(long long int x) {
        long long int n=abs(x);
        long long int p=0;
        while(n>0){
            int c=n%10;
            p*=10;
            p+=c;
            n/=10;
        }
        if(x>=0){
        return p;}
        else{
            return -p;
        }
        }
};