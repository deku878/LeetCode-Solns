// https://leetcode.com/problems/sqrtx

class Solution {
public:
    long long mySqrt(long long x) {
        int p;
       long long int l=1;
       long long int r=x;
        if(x==0){
           return x;
        }
        else{
            while(l<=r){
           long long int mid=l+(-l+r)/2;
            if(mid*mid==x){
            return mid;
            }
            else if(mid*mid>x){
                r=r-1;
            }
            else if(mid*mid<x){
                l=l+1;
            }}
        }
        return r;
    }
};