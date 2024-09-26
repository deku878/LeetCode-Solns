// https://leetcode.com/problems/flood-fill

class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int oldcolor,int color){
        int row = image.size();
        int coloumn = image[0].size();
        if(i<0||i>=row||j<0||j>=coloumn||image[i][j]!=oldcolor){
            return ;
        }
        image[i][j]=color;
        dfs(image,i+1,j,oldcolor,color);
        dfs(image,i,j+1,oldcolor,color);
        dfs(image,i,j-1,oldcolor,color);
        dfs(image,i-1,j,oldcolor,color);
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //firstly identify the color of the pixel ;
        int oldcolor = image[sr][sc];
        //compare it with the other pixel
        if(oldcolor==color){
            return image;
        }
        dfs(image,sr,sc,oldcolor,color);
        return image;
    }
};