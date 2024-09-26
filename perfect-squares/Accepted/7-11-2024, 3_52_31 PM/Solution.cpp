// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i-j*j>=0){
                    dp[i]=min(dp[i-j*j]+1,dp[i]);
                }
            }
        }
        return dp[n];
    }
};