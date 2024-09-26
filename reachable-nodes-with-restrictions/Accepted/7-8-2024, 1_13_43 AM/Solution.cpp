// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    vector<vector<int>> adj;
    unordered_set<int> restrictedSet;
    vector<bool> visited;
    
    void dfs(int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor] && restrictedSet.find(neighbor) == restrictedSet.end()) {
                dfs(neighbor);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        visited.resize(n, false);
        restrictedSet = unordered_set<int>(restricted.begin(), restricted.end());
        
        // Create adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Start DFS from node 0 if it's not restricted
        int count = 0;
        if (restrictedSet.find(0) == restrictedSet.end()) {
            dfs(0);
        }
        
        // Count reachable nodes
        for (bool nodeVisited : visited) {
            if (nodeVisited) {
                count++;
            }
        }
        
        return count;
    }
};