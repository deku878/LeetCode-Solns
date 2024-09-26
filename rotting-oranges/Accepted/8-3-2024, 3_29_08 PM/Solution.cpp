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
        int ans=0;
        while(!q.empty()){
            auto task=q.front().first;
            ans=task;
            auto x=q.front().second.first;
            auto y=q.front().second.second;
            q.pop();
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size()){
                    if(!vis[nx][ny] and grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    q.push({task+1,{nx,ny}});
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    return -1;
                }
            }
        }
        return ans;
    }
};