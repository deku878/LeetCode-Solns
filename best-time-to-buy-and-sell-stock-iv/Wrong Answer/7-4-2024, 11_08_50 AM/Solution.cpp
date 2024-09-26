// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
         k=max(k,n/2);
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++){
            int maxi=INT_MIN;
            for(int j=1;j<n;j++){
                if(dp[i-1][j-1]-a[j-1]>maxi){
                    maxi=dp[i-1][j-1]-a[j-1];
                }
                if(maxi+a[j]>dp[i][j-1]){
                    dp[i][j]=maxi+a[j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[k][n-1];
    }
};