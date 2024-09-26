// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int res(int i,int j,vector<int>&x,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minm=INT_MAX;
        for(int k=i;k<=j;k++){
            int r=x[j+1]-x[i-1]+res(i,k-1,x,dp)+res(k+1,j,x,dp);
            minm=min(minm,r);
        }
        return dp[i][j]=minm;
    }
    int minCost(int n, vector<int>& cuts) {
        int z=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return res(1,z,cuts,dp);
    }
};