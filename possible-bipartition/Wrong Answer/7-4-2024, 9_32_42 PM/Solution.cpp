// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool bich(vector<int>adj[],vector<int>&color,int node,int par){
        if(color[node]==-1){
            color[node]=1;
        }
        for(auto x:adj[node]){
            if(x!=par){
                if(color[x]==-1){
                    color[x]=1-color[node];
                    if(!bich(adj,color,x,node)){
                        return false;
                    }
                }
                else if(color[x]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<int>adj[n];
        for(int i=0;i<d.size();i++){
            adj[d[i][0]-1].push_back(d[i][1]-1);
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bich(adj,color,i,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};