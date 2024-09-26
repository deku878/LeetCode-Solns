// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool dfs(vector<bool>&vis,vector<bool>&inr,vector<vector<int>>ad,int curr){
        vis[curr]=true;
        inr[curr]=true;
        for(auto node:ad[curr]){
            if(!vis[node]){
                if(dfs(vis,inr,ad,node)){
                    return true;}
            }
            else if(inr[node]){
                return true;
            }
        }
        inr[curr]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n,vector<int>());
        vector<int> ans;

        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        vector<bool>vis(n,0);
        vector<bool>inr(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(vis,inr,adj,i)){
                    return false;
                }
            }
        }
        return true;
    }
};