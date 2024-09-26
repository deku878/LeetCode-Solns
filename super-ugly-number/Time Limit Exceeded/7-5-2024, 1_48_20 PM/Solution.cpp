// https://leetcode.com/problems/super-ugly-number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ugly(n,0);
        set<long long int>rex;
        for(int i=0;i<primes.size();i++){
            rex.insert(primes[i]);
        }
        ugly[0]=1;
        for(int i=1;i<n;i++){
            auto it=rex.begin();
            int p=*it;
            ugly[i]=*it;
            rex.erase(it);
            for(int i=0;i<primes.size();i++){
                long long int y=primes[i];
                y*=p;
                rex.insert(y);
            }
        }
        return ugly[n-1];
    }
};