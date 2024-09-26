// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=g[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+g[i][j]);
                }
                if(j-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+g[i][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};