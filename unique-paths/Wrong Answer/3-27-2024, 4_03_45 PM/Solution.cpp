// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n));

        for(int i =0; i<n; i++)
        {
            dp[0][i] = 1;
        }
        for(int j =0; j<m ; j++)
        {
            dp[j][0]=1;
        }
        dp[0][0]=0;
        for(int i=1 ; i<m ;i++)
        {
            for(int j =1; j<n; j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

        
    }
};
