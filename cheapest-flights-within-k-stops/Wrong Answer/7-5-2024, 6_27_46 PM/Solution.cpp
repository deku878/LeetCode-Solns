// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{src,0}});
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int p=flights[i][0];
            int q=flights[i][1];
            int r=flights[i][2];
            adj[p].push_back({q,r});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        while(!q.empty()){
            auto x=q.top();
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