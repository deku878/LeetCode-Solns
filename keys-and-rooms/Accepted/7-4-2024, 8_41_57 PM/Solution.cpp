// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    void dfs(vector<int>adj[],int node,int par,vector<int>&vis){
        vis[node]=1;
        for(auto y:adj[node]){
            if(!vis[y]){
                dfs(adj,y,node,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                int y=rooms[i][j];
                if(y!=i){
                    adj[i].push_back(y);
                }
            }
        }
        vector<int>vis(n,0);
        vis[0]=1;
        for(int i=0;i<vis.size();i++){
            if(vis[i]){
                dfs(adj,i,-1,vis);
            }
        }
        vis[0]=1;
        for(int i=0;i<n;i++){
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        cout<<count(vis.begin(),vis.end(),1)<<endl;
        return count(vis.begin(),vis.end(),1)==n;
    }
};