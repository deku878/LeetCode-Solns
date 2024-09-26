// https://leetcode.com/problems/word-break

class Solution {
public:
    bool start(const std::string &a, const std::unordered_set<std::string> &b, int i, int j, std::vector<std::vector<int>> &dp) {
    if (dp[i][j] != -1) return dp[i][j];
    if (b.find(a.substr(i, j-i+1)) != b.end()) {
        return dp[i][j] = true;
    }
    
    for (int k = i; k < j; ++k) {
        bool left = start(a, b, i, k, dp);
        bool right = start(a, b, k+1, j, dp);
        if (left and right) {
            return dp[i][j] = true;
        }
    }
    
    return dp[i][j] = false;
}
    bool wordBreak(string s, vector<string>& B) {
        std::unordered_set<std::string> b(B.begin(), B.end());
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
        return start(s,b,0,n-1,dp);       
    }
};