// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution {
public:
    long long maxans(vector<vector<long long>>& dp, vector<vector<int>>& points, int i, int j) {
        if (i == points.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        long long maxPoints = LLONG_MIN;
        for (int k = 0; k < points[0].size(); ++k) {
            long long pointsEarned = points[i][j] + maxans(dp, points, i + 1, k) - abs(j - k);
            maxPoints = max(maxPoints, pointsEarned);
        }
        
        return dp[i][j] = maxPoints;
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), -1));
        long long result = LLONG_MIN;
        for (int j = 0; j < points[0].size(); ++j) {
            result = max(result, maxans(dp, points, 0, j));
        }
        return result;
    }
};