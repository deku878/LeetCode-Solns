// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
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
        int res=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int step=x.first;
            int xc=x.second.first;
            int yc=x.second.second;
            res=step;
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                auto x_n=xc+dx[k];
                auto y_n=yc+dy[k];
                if(x_n>=0 and x_n<grid.size() and y_n>=0 and y_n<grid[0].size()){
                    if(!vis[x_n][y_n] and grid[x_n][y_n]==1){
                        q.push({step+1,{x_n,y_n}});
                        vis[x_n][y_n]=1;
                    }
                }
            }
        }
        int fo=0,ro=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    return -1;
                }
            }
        }
        return res;
    }
};