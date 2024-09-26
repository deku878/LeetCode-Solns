// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int solve(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j){
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=0,up=0,right=0,left=0;
        if(i+1<matrix.size() and matrix[i][j]<matrix[i+1][j]){
            down=1+solve(matrix,dp,i+1,j);
        }
        if(i-1>=0 and matrix[i][j]<matrix[i-1][j]){
            up=1+solve(matrix,dp,i-1,j);
        }
        if(j+1<matrix[0].size() and matrix[i][j]<matrix[i][j+1]){
            right=1+solve(matrix,dp,i,j+1);
        }
        if(j-1>=0 and matrix[i][j]<matrix[i][j-1]){
            left=1+solve(matrix,dp,i,j-1);
        }
        dp[i][j]=max({down,up,right,left});
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
               if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = std::max(ans, solve(matrix, dp, i, j));
            }
        }
        //   for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //       cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans+1;

    }
};