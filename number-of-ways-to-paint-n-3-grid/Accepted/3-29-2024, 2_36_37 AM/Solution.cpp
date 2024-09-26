// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    int mod = 1e9 + 7;
    int numOfWays(int n) {
        vector<long long int> v2(n,0); vector<long long int> v1(n,0);
        v2[0] = 6; v1[0] = 6;
        for(long long int i = 1; i<n;i++)
        {
            v1[i] = ((2*v2[i-1])%mod + (v1[i-1] * 3)%mod )%mod;
            v2[i] = ((2*v2[i-1])%mod + (v1[i-1] * 2)%mod )%mod;
            
        }
        return (int)((v2[n-1]%mod + v1[n-1]%mod)%mod);
    }

};