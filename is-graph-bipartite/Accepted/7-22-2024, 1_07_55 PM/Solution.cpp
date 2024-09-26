// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool dfs(int node,vector<int>&color,vector<vector<int>>&graph){
        if(color[node]==-1){
            color[node]=1;
        }
        for(auto i:graph[node]){
            if(color[i]==color[node]){
                return false;
            }
            else if(color[i]==-1){
                color[i]=1-color[node];
                if(!dfs(i,color,graph)){
                    return false;
                }
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