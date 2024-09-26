// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    void dfs(vector<vector<int>>& dp, vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size()) {
            return;
        }
        int dx[8] = {1, -1, 0, 1, -1, 0, 1, -1};
        int dy[8] = {1, -1, 1, 0, 0, -1, -1, 1};
        int minDist = INT_MAX;
        for (int k = 0; k < 8; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];
            if (nr < grid.size() && nr >= 0 && nc >= 0 && nc < grid[0].size()) {
                if (grid[nr][nc] == 1) {
                    int dist = abs(i - nr) + abs(j - nc);
                    dp[i][j] = min(dp[i][j], dist);
                    minDist = min(minDist, dist);
                } else if (dp[nr][nc] != -1) {
                    int dist = dp[nr][nc] + abs(i - nr) + abs(j - nc);
                    dp[i][j] = min(dp[i][j], dist);
                    minDist = min(minDist, dist);
                }
            }
        }
        if (minDist != INT_MAX) {
            dp[i][j] = minDist;
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    cnt++;
                }
            }
        }
        if (cnt == 0 || cnt == n * n) {
            return -1;
        }
        
        int maxDist = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(dp, grid, i, j);
                    maxDist = max(maxDist, dp[i][j]);
                }
            }
        }
        
        return maxDist;
    }
};