// https://leetcode.com/problems/nth-magical-number

class Solution {
public:
    long long  int MOD = 1e9+7;
    bool check(long long int a,long long int b,long long int mid,long long int n){
        long long int lcm=a*b/(__gcd(a,b));
        long long int ans=(mid/a)+(mid/b)-(mid/lcm);
        return ans>=n;
    }
    long long int nthMagicalNumber(long long int n, long long int a, long long int b) {
        long long int lo=min(a,b);
         long long int hi=16*(1e8);
        long long int ans=1;
        if(n==1){
            return min(a,b);
        }
        while(lo<=hi){
            long long int mid=lo+((hi-lo)/2);
            if(check(a,b,mid,n)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans%MOD;
    }
};