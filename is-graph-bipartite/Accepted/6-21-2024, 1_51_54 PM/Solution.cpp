// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool dfs(int node,vector<int>&color,vector<vector<int>>&graph){
        if(color[node]==-1){
        color[node]=1;}
        for(auto x:graph[node]){
            if(color[x]==-1){
                color[x]=1-color[node];
                if(!dfs(x,color,graph)){
                    return false;
                }
            }
            else if(color[node]==color[x]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        
        for(int i=0;i<color.size();i++){
            if(color[i]==-1){
                if(!dfs(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};