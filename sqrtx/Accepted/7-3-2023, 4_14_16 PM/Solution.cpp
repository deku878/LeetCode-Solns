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
            if(mid==x/mid){
            return mid;
            }
            else if(mid>x/mid){
                r=mid-1;
            }
            else if(mid<x/mid){
                l=mid+1;
            }}
        }
        return r;
    }
};