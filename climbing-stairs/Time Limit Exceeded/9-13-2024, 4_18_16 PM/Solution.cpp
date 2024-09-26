// https://leetcode.com/problems/climbing-stairs

class Solution {
        public:
        int helper(int n,vector<int>dp){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }
    int climbStairs(int n) {
        vector< int>op(10000,-1);
        return helper(n,op);
    }

};