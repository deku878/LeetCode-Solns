// https://leetcode.com/problems/powx-n

class Solution {
public:
    double solve(double x,long long int n){
        if(n==0){
            return 1;
        }
        else if(n<=0){
            return solve(1/x,-1*n);
        }
        else{
            if(n%2==0){
                return solve(x*x,n/2);
            }
            else{
                return x*solve(x*x,(n-1)/2);
            }
        }
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};