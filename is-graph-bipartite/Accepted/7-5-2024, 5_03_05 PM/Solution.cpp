// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isbi(vector<vector<int>>&adj,vector<int>&co,int node,int par){
        if(co[node]==-1){
            co[node]=1;
        }
        for(auto y:adj[node]){
            if(co[y]==-1){
                co[y]=1-co[node];
                if(!isbi(adj,co,y,node)){
                    return false;
                }
            }
            else if(co[y]==co[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>co(n,-1);
        for(int i=0;i<n;i++){
            if(co[i]==-1){
                if(!isbi(graph,co,i,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};