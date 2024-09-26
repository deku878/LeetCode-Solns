// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& p, int src, int dst, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){
            adj[p[i][0]].push_back({p[i][1],p[i][2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            for(auto y:adj[x.second]){
                if(dis[x.second]+y.second<dis[y.first] and x.first<=k){
                 dis[y.first]=dis[x.second]+y.second;
                 q.push({x.first+1,y.first});
                }
            }
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};