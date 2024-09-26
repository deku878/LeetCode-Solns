// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    int mint(vector<vector<int>>& dp, vector<int>& tasks, int sessionTime, int currentSum, int index, int sessions) {
        if (index >= tasks.size()) {
            return sessions;
        }
        if (dp[index][currentSum] != -1) {
            return dp[index][currentSum];
        }

        // Try to add the current task to the current session
        int ans = INT_MAX;
        if (currentSum + tasks[index] <= sessionTime) {
            ans = mint(dp, tasks, sessionTime, currentSum + tasks[index], index + 1, sessions);
        }

        // Or start a new session with the current task
        ans = min(ans, mint(dp, tasks, sessionTime, tasks[index], index + 1, sessions + 1));
        
        return dp[index][currentSum] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<vector<int>> dp(n + 1, vector<int>(sessionTime + 1, -1));
        return mint(dp, tasks, sessionTime, 0, 0, 1);
    }
};
