// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>>q;
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        vector<vector<int>>vis1(image.size(),vector<int>(image[0].size(),0));
        vis1=image;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int prev=image[sr][sc];
        vis1[sr][sc]=color;
        while(!q.empty()){
            auto x=q.front().first;
            auto y=q.front().second;
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<image.size() and ny<image[0].size()){
                    if(vis[nx][ny]==0 and image[nx][ny]==prev){
                        q.push({nx,ny});
                        vis1[nx][ny]=color;
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return vis1;
    }
};