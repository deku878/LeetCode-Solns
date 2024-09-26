// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
       #define ll long long
    #define MOD 1000000007
    int numOfWays(int n) {
        vector<ll> all_diff(n),two_same(n);
        all_diff[0] = two_same[0] = 6;
        for(int i=1;i<n;i++){
            all_diff[i] = ((all_diff[i-1]*2) + (two_same[i-1]*2))%MOD;
            two_same[i] = ((all_diff[i-1]*2) + (two_same[i-1]*3))%MOD;
        }

        ll ans = (all_diff.back() + two_same.back())%MOD;
        return ans;
    }
};