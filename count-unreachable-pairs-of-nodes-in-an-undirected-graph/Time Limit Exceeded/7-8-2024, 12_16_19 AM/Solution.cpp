// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

class Solution {
public:
    vector<int>parent,size;
    int par(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=par(parent[x]);
    }
    void uni(int x,int y){
        int p1=par(x);
        int p2=par(y);
        if(p1==p2){
            return;
        }
        if(size[p1]<size[p2]){
            size[p2]+=size[p1];
            parent[p1]=p2;
        }
        else{
            size[p1]+=size[p2];
            parent[p2]=p1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //find the number of components and the nodes in each components
        vector<int>adj[n];
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(auto u:adj[i]){
                if(!vis[u]){
                    uni(i,u);
                }
            }
        }
        map<long long int,long long int>mp;
        for(int i=0;i<n;i++){
            mp[parent[i]]++;
        }
        vector<long long int>x;
        for(auto m:mp){
            x.push_back(m.second);
        }
        sort(x.begin(),x.end());
        long long int ans=0;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                ans+=x[i]*x[j];
            }
        }
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        return ans;
    }
};