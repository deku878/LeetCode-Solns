// https://leetcode.com/problems/delete-columns-to-make-sorted-iii


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);
        
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < j; ++i) {
                bool valid = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][i] > strs[k][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        int maxLen = *max_element(dp.begin(), dp.end());
        return m - maxLen;
    }
};