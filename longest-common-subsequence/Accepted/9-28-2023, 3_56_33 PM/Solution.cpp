// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    
    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                a[i][j] = 1 + a[i + 1][j + 1];
            } else {
                a[i][j] = max(a[i + 1][j], a[i][j + 1]);
            }
        }
    }
    
    return a[0][0];
}

};