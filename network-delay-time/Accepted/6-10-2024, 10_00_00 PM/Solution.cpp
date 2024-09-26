// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        
        for(auto it: times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        
        pq.push({0,k});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int adjwt = it.second;
                
                if(weight+adjwt<dist[adjnode])
                {
                    dist[adjnode]=weight+adjwt;
                    pq.push({weight+adjwt,adjnode});
                }
            }
        }
        
        int mini = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(i!=k and dist[i]==INT_MAX)
            {
                return -1;
            }
            
            mini = max(mini,dist[i]);
            
        }
                               
        return mini;
    
        }
};