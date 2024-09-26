// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    vector<int> parent, rank, size;
    
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }
    
    void unionSet(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u != root_v) {
            // Union by rank
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initialize parent pointers
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Union stones with the same row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unionSet(i, j);
                }
            }
        }
        
        // Count number of connected components
        unordered_set<int> components;
        for (int i = 0; i < n; ++i) {
            components.insert(find(i));
        }
        
        return n - components.size();
    }
};
