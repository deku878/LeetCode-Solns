// https://leetcode.com/problems/detonate-the-maximum-bombs

class Solution {
private:
    void bfs(vector<vector<int>>& graph, vector<bool>& visited, long long &cnt, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cnt++; 
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        long long n = bombs.size();
        vector<vector<int>> graph(n);
        for (long long i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for (long long j = 0; j < n; j++) {
                if (i != j) {
                    long long x = abs(x1 - bombs[j][0]);
                    long long y = abs(y1 - bombs[j][1]);
                    if (x * x + y * y <= r1 * r1) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        long long ans = 0;
        for (long long  i = 0; i < n; i++) {
            long long  cnt = 0;
            vector<bool> visited(n, false);
            bfs(graph, visited, cnt, i);
            ans = max(ans, cnt);
        }
        return ans; 
    }
};
