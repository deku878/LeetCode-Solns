// https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:
    int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));

        dp[row][col] = 1.0;

        for (int m = 1; m <= k; m++) {
            vector<vector<double>> new_dp(n,vector<double>(n, 0.0));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int i = 0; i < 8; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            new_dp[nx][ny] += dp[x][y] / 8.0;
                        }
                    }
                }
            }
            dp = move(new_dp);
        }

        double ans = 0.0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                ans += dp[x][y];
            }
        }

        return ans;
    }
};
