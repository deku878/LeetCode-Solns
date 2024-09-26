// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&vis,int node){
        vis[node]=1;
        for(auto child:adj[node]){
            if(vis[child]==0){
                dfs(adj,vis,child);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& iy) {
        int n=iy.size();
        vector<int>adj[n];
        for(int i=0;i<iy.size();i++){
            for(int j=0;j<iy[0].size();j++){
                if(iy[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};