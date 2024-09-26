// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        vector<vector<int>> dp(n, vector<int>(2, 1));
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
            } else if (arr[i] < arr[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            maxLen = max(maxLen, max(dp[i][0], dp[i][1]));
        }

        return maxLen;
    }
};