// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
                int maxm=INT_MIN;
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i]-'0';
            maxm=max(maxm,dp[0][i]);
        }
        for(int j=0;j<n;j++){
            dp[j][0]=matrix[j][0]-'0';
            maxm=max(maxm,dp[j][0]);
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                maxm=max(maxm,dp[i][j]*dp[i][j]);
                }
            }
        }
        return maxm;
    }
};