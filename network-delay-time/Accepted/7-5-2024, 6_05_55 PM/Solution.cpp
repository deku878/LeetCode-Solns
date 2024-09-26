// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, INT_MAX); // dis array with size n + 1
        dis[k-1] = 0; // Start from node k (1-based indexing)
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1}); // Push {distance, node} where distance is 0 for node k
        
        vector<pair<int, int>> adj[n]; // Adjacency list
        
        for (auto& edge : times) {
            int x = edge[0] - 1; // Convert to 0-based indexing
            int y = edge[1] - 1; // Convert to 0-based indexing
            int z = edge[2];
            adj[x].push_back({y, z});
        }
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            int curr_dis = curr.first;
            
            if (curr_dis > dis[node]) continue; // Skip outdated entries
            
            for (auto& next : adj[node]) {
                int neighbor = next.first;
                int weight = next.second;
                int new_dis = curr_dis + weight;
                
                if (new_dis < dis[neighbor]) {
                    dis[neighbor] = new_dis;
                    pq.push({new_dis, neighbor});
                }
            }
        }
        
        int max_dis = 0;
        for (int i = 0; i < n; ++i) {
            if (dis[i] == INT_MAX) return -1; // Node i is not reachable
            max_dis = max(max_dis, dis[i]); // Update maximum delay time
        }
        
        return max_dis;
    }
};
