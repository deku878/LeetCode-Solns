// https://leetcode.com/problems/super-ugly-number

```typedef long long ll;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<ll> s1;
        s1.insert(1);
        int x = 0;
        ll temp = 0;
        while(x++ < n){
            temp = *s1.begin();
            s1.erase(temp);
            for(int i = 0;i < primes.size();i++){
                s1.insert(temp * primes[i]);
            }
        }
        return temp;
    }
};
