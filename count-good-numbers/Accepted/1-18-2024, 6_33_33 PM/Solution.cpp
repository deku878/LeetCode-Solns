// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    const int MOD = 1000000007;
    
    long long int power(long long int x, long long int y){
        if(y==0) return 1;
        
        long long int res = power(x, y/2);
        res = (res * res)%MOD;

        if(y%2==1) res = (res * x)%MOD;
        return res;
    }


    int countGoodNumbers(long long n) {        
        long long int odd = n/2;
        long long int even = n - odd;

        return (power(5, even) * power(4, odd))%MOD;
    }
};
