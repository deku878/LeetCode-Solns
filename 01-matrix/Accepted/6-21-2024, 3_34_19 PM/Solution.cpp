// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>m(mat.size(),vector<int>(mat[0].size()));
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size()));
        m=mat;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto times=q.front();
            int dis=times.first;
            int idx1=times.second.first;
            int idx2=times.second.second;
            q.pop();
            m[idx1][idx2]=dis;
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            for(int k=0;k<4;k++){
                int nr=idx1+dx[k];
                int nc=idx2+dy[k];
                if(nr>=0 and nr<mat.size() and nc>=0 and nc<mat[0].size()){
                    if(!vis[nr][nc] and mat[nr][nc]!=0){
                        vis[nr][nc]=1;
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
        }
        return m;
    }
};