// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Priority queue to store {current cost, current city, current stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});
        
        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }
        
        // Distance vector to store minimum cost to reach each city
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();
            
            // If we reach the destination
            if (u == dst) {
                return cost;
            }
            
            // If stops exceed the allowed limit
            if (stops > k) {
                continue;
            }
            
            for (const auto& [v, price] : adj[u]) {
                int newCost = cost + price;
                // We only update the queue if the new path is cheaper
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }
        
        return -1; // If no path is found within k stops
    }

};