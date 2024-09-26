// https://leetcode.com/problems/nth-magical-number

class Solution {
public:
    bool check(int a,int b,int mid,int n){
        long long int lcm=mid/(__gcd(a,b));
        long long int ans=(mid/a)+(mid/b)-(mid/lcm);
        return ans>=n;
    }
    long long int nthMagicalNumber(int n, int a, int b) {
        long long int hi=16*(1e8);
        long long int lo=1;
        long long int ans=1;
        if(n==1){
            return min(a,b);
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(a,b,mid,n)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};