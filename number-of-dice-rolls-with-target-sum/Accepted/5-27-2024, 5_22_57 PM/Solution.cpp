// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
         long long m = 1e9 + 7;
         int t=target;
        vector<vector<long long>> dp(n + 1, vector<long long>(t + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= t; ++j) {
                for (int x = 1; x <= k; ++x) {
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % m;
                    }
                }
            }
        }

        return dp[n][t];
    }
};