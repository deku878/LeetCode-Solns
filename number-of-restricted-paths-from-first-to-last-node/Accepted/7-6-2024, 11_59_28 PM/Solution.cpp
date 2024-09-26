// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node

class Solution {
public: 
    
    /*
        This is a typical dp on graphs problem where we first find out the shortest routes from n to every other node, then we perform dfs on
        graph starting from node n,such that we go to next dfs only if the corresponding edge's distance is greater than now node's.
        We continue this untill we get to 1, and in the way we look for strictly increasing paths as well.
        We use DP here as from current node, there can be multiple strictly increasing paths to reach 1. \U0001f62a
    */
    
    int dfs(vector<pair<int,int>> edge[],vector<int> &distance,int n,vector<int> &dp){
        int inf=1e9+7;
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int ans=0;
        for(auto it:edge[n]){
            if(distance[it.first]>distance[n]){
                ans+=((dfs(edge,distance,it.first,dp))%(inf))%inf;
                ans=ans%inf;
            }
        }
        return dp[n]=ans%inf;
    }
    
    void djikstra(vector<pair<int,int>> edge[],vector<int> &distance,int n){
        distance[n]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,n});
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(p.first > distance[p.second])
                continue;
            for(auto it:edge[p.second]){
                if(distance[it.first] > distance[p.second]+it.second){
                    distance[it.first]=distance[p.second]+it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> distance(n+1,INT_MAX);
        vector<pair<int,int>> edge[n+1];
        for(auto it:edges){
            edge[it[0]].push_back({it[1],it[2]});
            edge[it[1]].push_back({it[0],it[2]});
        }
        djikstra(edge,distance,n);
        vector<int> dp(n+1,-1);
        return dfs(edge,distance,n,dp);
        return 0;
    }
};
