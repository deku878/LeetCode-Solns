// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<vector<int>>&x,vector<int>&vis,int vertex){
        vis[vertex]=1;
        for(auto k:x[vertex]){
            if(!vis[k]){
                dfs(x,vis,k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        vector<vector<int>>adj(is.size(),vector<int>());
        for(int i=0;i<is.size();i++){
            for(int j=0;j<is[0].size();j++){
                if(i!=j and is[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int>vis(is.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};