// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int p;
        int l=1;
        int r=x;
        int mid=(l+r)/2;
        if(x==0){
           return x;
        }
        else{
            while(l<=r){
            if(mid==x/mid){
            return mid;
            }
            else if(mid>x/mid){
                r=r-1;
            }
            else if(mid<x/mid){
                l=l+1;
            }}
        }
        return r;
    }
};