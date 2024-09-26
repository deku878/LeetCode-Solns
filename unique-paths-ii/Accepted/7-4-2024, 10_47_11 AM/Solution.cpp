// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(g[i][0]==1){
                break;
            }
            else{
                dp[i][0]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(g[0][i]==1){
                break;
            }
            else{
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(g[i][j]==0){
                    if(dp[i-1][j]!=0){
                        dp[i][j]=dp[i][j]+dp[i-1][j];
                    }
                    if(dp[i][j-1]!=0){
                        dp[i][j]=dp[i][j]+dp[i][j-1];
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};