// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int maxm=INT_MAX;
        for(int i=0;i<m;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]);
                dp[i][j]+=triangle[i][j];
            }
        }
        return dp[0][0];
    }
};