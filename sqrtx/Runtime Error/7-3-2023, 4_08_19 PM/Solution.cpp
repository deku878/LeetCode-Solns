// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int p;
        int l=1;
        int r=x;
        if(x==0){
           return x;
        }
        else{
            while(l<=r){
            int mid=(l+r)/2;
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