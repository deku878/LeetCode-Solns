// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<char>>&x,int i,int j){
        if(i<0 and j<0 and i>=x.size() and j>=x[0].size()){
            return;
        }
        if(x[i][j]=='?' or x[i][j]=='X'){
            return ;
        }
        vis[i][j]=1;
        x[i][j]='?';
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int new_r=i+dx[k];
            int new_c=j+dy[k];
            if(new_r>=0 and new_c>=0 and new_r<x.size() and new_c<x[0].size()){
                if(!vis[new_r][new_c]){
                    dfs(vis,x,new_r,new_c);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            if(!vis[i][board[0].size()-1]){
                dfs(vis,board,i,board[0].size()-1);
            }
        }
        for(int i=0;i<board.size();i++){
            if(!vis[i][0]){
                dfs(vis,board,i,0);
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(!vis[0][i]){
                dfs(vis,board,0,i);
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(!vis[board.size()-1][i]){
                dfs(vis,board,board.size()-1,i);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='?'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='?'){
                    board[i][j]='O';
                }
            }
        }
    }
};