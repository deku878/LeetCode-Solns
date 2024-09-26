// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edWt = it.second;
                
                if(stops <= k && cost+edWt < dist[adjNode]) {
                    dist[adjNode] = cost + edWt;
                    q.push({cost+edWt, {adjNode, stops+1}});
                }
            }
            
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
