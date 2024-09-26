// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int cntw(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&d){
        if(d[n][m]==1){
            return 0;
        }
        if(n==0 and m==0){
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up=0,left=0;
        if(n-1>=0){
            up=cntw(n-1,m,dp,d);
        }
        if(m-1>=0){
            left=cntw(n,m-1,dp,d);
        }
        return dp[n][m]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return cntw(n-1,m-1,dp,g);
    }
};