// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int dp(int m,int n,vector<vector<int>>&dp1){
        if(m<0 or n<0){
            return 0;
        }
        if(m==0 or n==0){
            return 1;
        }
        if(dp1[m][n]!=-1){
            return dp1[m][n];
        }
        int up=dp(m-1,n,dp1);
        int left=dp(m,n-1,dp1);
        return dp1[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp1(m,vector<int>(n,-1));
        return dp(m-1,n-1,dp1);
    }
};