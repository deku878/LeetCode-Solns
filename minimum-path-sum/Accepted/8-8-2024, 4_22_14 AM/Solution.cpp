// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int maxpath(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&d){
        if(n==0 and m==0){
            return d[n][m];
        }
        if(dp[n][m]!=INT_MAX){
            return dp[n][m];
        }
        int up=INT_MAX,left=INT_MAX;
        if(n-1>=0){
            up=d[n][m]+maxpath(n-1,m,dp,d);
        }
        if(m-1>=0){
            left=d[n][m]+maxpath(n,m-1,dp,d);
        }
        return dp[n][m]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        return maxpath(n-1,m-1,dp,g);
    }
};