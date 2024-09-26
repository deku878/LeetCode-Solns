// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int t=1;t<=k;t++){
            int maxm=INT_MIN;
            for(int d=1;d<n;d++){
                if(dp[t-1][d-1]-p[d-1]>maxm){
                    maxm=dp[t-1][d-1]-p[d-1];
                }
                if(maxm+p[d]>dp[t][d-1]){
                    dp[t][d]=maxm+p[d];
                }
                else{
                    dp[t][d]=dp[t][d-1];
                }
            }
        }
        return dp[k][n-1];
    }
};