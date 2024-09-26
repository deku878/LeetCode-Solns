// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&vis,int node,int par){
        vis[node]=1;
        for(auto y:adj[node]){
            if(!vis[y]){
                dfs(adj,vis,y,node);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& iy) {
        int n=iy.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(iy[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i,-1);
            }
        }
        return cnt;
    }
};