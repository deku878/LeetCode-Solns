// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int mod = 1000000007;
    int memo(int m, int n, int move, int i, int j,
             vector<vector<vector<int>>>& dp) {
        if (move <= 0 || i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (dp[i][j][move] != -1) {
            return dp[i][j][move];
        }
        long long count = 0;
        if (i == 0) {
            count++;
        }
        if (i == m - 1) {
            count++;
        }
        if (j == 0) {
            count++;
        }
        if (j == n - 1) {
            count++;
        }
        return dp[i][j][move] = (count + memo(m, n, move - 1, i - 1, j, dp) +
                                 memo(m, n, move - 1, i + 1, j, dp) +
                                 memo(m, n, move - 1, i, j - 1, dp) +
                                 memo(m, n, move - 1, i, j + 1, dp)) %
                                mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        ////memo
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(maxMove+1, -1)));
        return memo(m, n, maxMove, startRow, startColumn, dp);

    }
};
