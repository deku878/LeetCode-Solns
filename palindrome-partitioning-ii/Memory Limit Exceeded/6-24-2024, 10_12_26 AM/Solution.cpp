// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
      bool isp(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int res(int i, int j, vector<vector<long long int>>& dp, string s) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (isp(s, i, j)) {
            return dp[i][j] = 0;
        }
        int minCuts = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isp(s, i, k)) {
                minCuts = min(minCuts, 1 + res(k + 1, j, dp, s));
            }
        }
        return dp[i][j] = minCuts;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return res(0, n - 1, dp, s);
    }

};
