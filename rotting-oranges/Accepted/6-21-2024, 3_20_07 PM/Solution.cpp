// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
       int ti=0;
       while(!q.empty()){
        auto x=q.front();
        int ro=x.second.first;
        int co=x.second.second;
        int times=x.first;
        ti=times;
        q.pop();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int new_ro=ro+dx[k];
            int new_co=co+dy[k];
           if(new_ro>=0 and new_ro<grid.size() and new_co>=0 and new_co<grid[0].size()){
            if(grid[new_ro][new_co]==1 and !vis[new_ro][new_co]){
                vis[new_ro][new_co]=1;
                q.push({times+1,{new_ro,new_co}});
            }
        }
        }
        }
        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[0].size();j++){
                if(!vis[i][j] and grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ti;
    }
};