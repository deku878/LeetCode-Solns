// https://leetcode.com/problems/flood-fill

class Solution {
public:
    void dfs(vector<vector<int>>&image,vector<vector<int>>&vis,int i,int j,int color,int st){
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size()){
            return ;
        }
        else if(vis[i][j]==1){
            return;
        }
        else if(image[i][j]==color){
            return;
        }
        if(image[i][j]==st){
        image[i][j]=color;
        vis[i][j]=1;
        dfs(image,vis,i+1,j,color,st);
        dfs(image,vis,i-1,j,color,st);
        dfs(image,vis,i,j+1,color,st);
        dfs(image,vis,i,j-1,color,st);}
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        if(image[sr][sc]==color){
            return image;
        }
        int st=image[sr][sc];
        dfs(image,vis,sr,sc,color,st);
        return image;
    }
};