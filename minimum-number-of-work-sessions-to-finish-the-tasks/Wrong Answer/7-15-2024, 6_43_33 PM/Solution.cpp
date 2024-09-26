// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    int mint(vector<int>& tasks, int sessionTime, int index, vector<int>& dp) {
        if (index >= tasks.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        int minSessions = INT_MAX;
        int currentSum = 0;
        
        for (int i = index; i < tasks.size(); ++i) {
            currentSum += tasks[i];
            if (currentSum <= sessionTime) {
                // Recursively find the minimum sessions starting from the next task
                minSessions = min(minSessions, 1 + mint(tasks, sessionTime, i + 1, dp));
            }
        }

        return dp[index] = minSessions;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> dp(n, -1); // dp[i] will store the minimum sessions starting from task i
        return mint(tasks, sessionTime, 0, dp);
    }
};
