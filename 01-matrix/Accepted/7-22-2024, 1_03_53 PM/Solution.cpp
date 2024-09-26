// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>res(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int ans=x.first;
            int xc=x.second.first;
            int yc=x.second.second;
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nxc=xc+dx[k];
                int nyc=yc+dy[k];
                if(nxc>=0 and nxc<mat.size() and nyc>=0 and nyc<mat[0].size()){
                    if(!vis[nxc][nyc]){
                        res[nxc][nyc]=ans+1;
                        q.push({ans+1,{nxc,nyc}});
                        vis[nxc][nyc]=1;
                    }
                }
            }
        }
        return res;
    }
};