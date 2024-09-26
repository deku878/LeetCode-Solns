// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int sub(vector<pair<int,int>>& a, int idx, int no, int nz, vector<vector<vector<int>>>& dp) {
        int n = a.size();
        if (idx == n || (no == 0 && nz == 0)) {
            return 0;
        }
        if (dp[idx][no][nz] != -1) {
            return dp[idx][no][nz];
        }
        
        int inc = 0, exc = 0;
        if (a[idx].second <= nz && a[idx].first <= no) {
            inc = 1 + sub(a, idx + 1, no - a[idx].first, nz - a[idx].second, dp);
        }
        exc = sub(a, idx + 1, no, nz, dp);
        
        return dp[idx][no][nz] = max(inc, exc);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> a;
        for (auto& s : strs) {
            int one = 0, zero = 0;
            for (char c : s) {
                if (c == '1') one++;
                else zero++;
            }
            a.push_back({zero, one});
        }
        
        int x = strs.size();
        vector<vector<vector<int>>> dp(x, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        int ans = sub(a, 0, m, n, dp);
        return ans;
    }
};
