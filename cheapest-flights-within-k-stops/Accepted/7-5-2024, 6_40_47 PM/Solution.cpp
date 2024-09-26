// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            adj[from].push_back({to, cost});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int node=x.second.first;
            int wt=x.first;
            int stops=x.second.second;
            for(auto y:adj[node]){
                if(y.second+wt<dis[y.first] and stops<=k){
                    dis[y.first]=y.second+wt;
                    q.push({dis[y.first],{y.first,stops+1}});
                }
            }
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};