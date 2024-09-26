// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    void dfs(int node,int par,vector<int>&p,vector<vector<int>>&adj,vector<vector<int>>& res,vector<int>&vis){
        vis[node]=1;
        p.push_back(node);
        if(node==adj.size()-1){

            res.push_back(p);
        }
        else{
        for(auto y:adj[node]){
            if(!vis[y]){
                dfs(y,node,p,adj,res,vis);
            }
        }}
        p.pop_back();
        vis[node]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>res;
        vector<int>u;
        vector<int>vis(n,0);
        dfs(0,-1,u,graph,res,vis);
        return res;
    }
};