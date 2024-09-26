// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                q.push({0,{i,j}});
                dp[i][j]=0;
                vis[i][j]=1;}
            }
        }
        while(!q.empty()){
            auto x=q.front();
            int dis=x.first;
            int xc=x.second.first;
            int yc=x.second.second;
            q.pop();
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nxc=xc+dx[i];
                int nyc=yc+dy[i];
                if(nxc>=0 and nxc<mat.size() and nyc>=0 and nyc<mat[0].size() and !vis[nxc][nyc]){
                    q.push({dis+1,{nxc,nyc}});
                    vis[nxc][nyc]=1;
                    dp[nxc][nyc]=dis+1;
                }
            }
        }
        return dp;
    }
};