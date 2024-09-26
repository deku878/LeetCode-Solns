// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    int numOfWays(int n) {
        vector<vector<long long int>>dp(n,vector<long long int>(2,0));
        dp[0][0]=6;
        int mod=1e9+7;
        //same colour
        dp[0][1]=6;
        //diff colour
        for(int i=1;i<n;i++){
            dp[i][0]=((2*dp[i-1][1])%mod+(3*dp[i-1][0])%mod)%mod;
            dp[i][1]=((2*dp[i-1][1])%mod+(2*dp[i-1][0])%mod)%mod;
        }
        return (dp[n-1][0]%mod+dp[n-1][1]%mod)%mod;
    }
};