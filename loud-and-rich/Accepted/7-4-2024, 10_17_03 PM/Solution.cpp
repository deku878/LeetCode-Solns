// https://leetcode.com/problems/loud-and-rich

class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& quiet, int node, vector<int>& vis, vector<int>& res) {
        vis[node] = 1;
        res[node] = node; // Initially, the quietest person richer or equally rich as node is itself
        
        for (auto x : adj[node]) {
            if (!vis[x]) {
                dfs(adj, quiet, x, vis, res);
            }
            // If the person x is quieter than the current quietest for node, update it
            if (quiet[res[x]] < quiet[res[node]]) {
                res[node] = res[x];
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        
        for (const auto& r : richer) {
            adj[r[1]].push_back(r[0]);
        }
        
        vector<int> res(n, -1); // To store the quietest person richer or equally rich as person i
        vector<int> vis(n, 0);  // Visited array
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, quiet, i, vis, res);
            }
        }
        
        return res;
    }
};