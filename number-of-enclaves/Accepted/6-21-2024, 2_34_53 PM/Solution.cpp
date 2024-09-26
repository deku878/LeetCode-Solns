// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    void dfs(vector<vector<int>>&x,vector<vector<int>>&vis,int i,int j){
        if(i<0 or j<0 or i>=x.size() or j>=x[0].size() or vis[i][j]==1){
            return;
        }
        if(x[i][j]==69 or x[i][j]==0){
            return;
        }
        vis[i][j]=1;
        x[i][j]=69;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int new_r=i+dx[k];
            int new_c=j+dy[k];
            if(new_r>=0 and new_c>=0 and new_r<x.size() and new_c<x[0].size()){
                if(!vis[new_r][new_c]){
                    dfs(x,vis,new_r,new_c);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
        if(!vis[i][0]){
        dfs(grid,vis,i,0);}}
        for(int i=0;i<m;i++){
            if(!vis[0][i]){
        dfs(grid,vis,0,i);}
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1]){
            dfs(grid,vis,i,m-1);}
        }
        for(int i=0;i<m;i++){
            if(!vis[n-1][i]){
            dfs(grid,vis,n-1,i);}
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};