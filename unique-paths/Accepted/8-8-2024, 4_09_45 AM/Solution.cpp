// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int cntw(int m,int n,vector<vector<int>>&dp){
        if(n==0 or m==0){
            return 1;
        }
        if(n<0 or m<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=cntw(m-1,n,dp);
        int left=cntw(m,n-1,dp);

        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return cntw(m-1,n-1,dp);
    }
};