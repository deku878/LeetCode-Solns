// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool isp(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int res(int i, int j, vector<int>& dp, string s) {
        if (i == s.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int minCuts = INT_MAX;
        for (int k = i; k <= j; k++) {
            if (isp(i, k, s)) {
                minCuts = min(minCuts, 1 + res(k + 1, j, dp, s));
            }
        }
        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return res(0, n - 1, dp, s) - 1;
    }
};
