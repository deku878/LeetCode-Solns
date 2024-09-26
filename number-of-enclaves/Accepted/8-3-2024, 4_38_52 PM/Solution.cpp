// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
         vector<vector<int>>kl(board.size(),vector<int>(board[0].size()));
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        kl=board;
        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            if(vis[i][0]==0 and board[i][0]==1){
                vis[i][0]=1;
                kl[i][0]=6;
                q.push({i,0});
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(vis[0][i]==0 and board[0][i]==1){
                vis[0][i]=1;
                kl[0][i]=6;
                q.push({0,i});
            }
        }
        for(int i=0;i<board.size();i++){
            if(vis[i][board[i].size()-1]==0 and board[i][board[i].size()-1]==1){
                vis[i][board[i].size()-1]=1;
                kl[i][board[i].size()-1]=6;
                q.push({i,board[i].size()-1});
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(vis[board.size()-1][i]==0 and board[board.size()-1][i]==1){
                vis[board.size()-1][i]=1;
                kl[board.size()-1][i]=6;
                q.push({board.size()-1,i});
            }
        }
        while(!q.empty()){
            auto x=q.front().first;
            auto y=q.front().second;
            q.pop();
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<board.size() and ny>=0 and ny<board[0].size() and !vis[nx][ny] and board[nx][ny]==1){
                    vis[nx][ny]=1;
                    kl[nx][ny]=6;
                    q.push({nx,ny});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(kl[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};