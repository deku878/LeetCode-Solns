// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

class Solution {
public:
    int maxscore(vector<int>&n,int i,int j,vector<vector<int>>&dp){
        if(j-i<2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        //recursion kaise likhenge paaji
        for(int k=i+1;k<j;k++){
            int x=maxscore(n,i,k,dp)+(n[i]*n[k]*n[j])+maxscore(n,k,j,dp);
            ans=min(ans,x);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        //n-2 triangles me triangulate krna hai
        //this is mcm problem na
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),-1));
        return maxscore(values,0,values.size()-1,dp);
    }
};