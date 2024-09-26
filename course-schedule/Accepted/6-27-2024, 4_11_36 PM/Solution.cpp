// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool dfs(vector<bool>&inrec,vector<bool>&vis,vector<vector<int>>&adj,int node){
        vis[node]=true;
        inrec[node]=true;
        for(auto x:adj[node]){
            if(!vis[x]){
            if(dfs(inrec,vis,adj,x)){
                    return true;
                }
            }
            else if(inrec[x]){
                return true;
            }
        }
        inrec[node]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
        //directed graph me cycle nikalni hh isme bas
        vector<bool>inrec(n,false);
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n,vector<int>());
        for(auto x: pr){
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
            if(dfs(inrec,vis,adj,i)){
                return false;
            }}
        }
        return true;
    }
};