// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++){
            int maxm=INT_MIN;
            for(int j=1;j<n;j++){
                if(maxm<dp[i-1][j-1]-p[j-1]){
                    maxm=dp[i-1][j-1]-p[j-1];
                }
                if(maxm+p[j]>dp[i][j-1]){
                    dp[i][j]=maxm+p[j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[k][n-1];
    }
};