// https://leetcode.com/problems/count-primes

class Solution {
public:
    vector<bool>sieve(long long int n){
        vector<bool>f(n+1,true);
        f[0]=false;
        f[1]=false;
        for(int i=2;i<n;i++){
            if(f[i]==true){
            for(int j=2*i;j<n+1;j+=i){
                f[j]=false;
            }}
        }
        return f;
    }
    int countPrimes(int n) {
        vector<bool>c=sieve(n);
        long long int count=0;
        for(int i=0;i<n+1;i++){
            if(c[i]==true){
                count++;
            }
        }
        return count;
    }
};