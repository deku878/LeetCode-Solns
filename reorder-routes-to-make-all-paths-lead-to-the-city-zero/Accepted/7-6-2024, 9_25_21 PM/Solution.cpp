// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int count = 0;

    void dfs(int node, int par, vector<vector<pair<int, int>>>& adj) {
        for (auto& p : adj[node]) {
            int x = p.first;
            int direction = p.second;
            
            // If x is not the parent and we can reorder the edge (direction == 1),
            // increment the count and continue DFS from node x.
            if (x != par ) {
                if(direction==1){
                count++;}
                dfs(x, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        count = 0;
        
        // Initialize adjacency list
        vector<vector<pair<int, int>>> adj(n);
        
        // Build the graph
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            
            // Add the edge u -> v with direction 1 (reversible)
            adj[u].push_back({v, 1});
            // Add the edge v -> u with direction 0 (not reversible)
            adj[v].push_back({u, 0});
        }
        
        // Perform DFS starting from node 0 (or any node, as the graph is connected)
        dfs(0, -1, adj);
        
        return count;
    }
};
