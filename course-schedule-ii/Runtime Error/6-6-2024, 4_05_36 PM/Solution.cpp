// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    void dfs(vector<vector<int>>adj,stack<int>&st,int curr,vector<bool>&vis){
        for(auto x:adj[curr]){
            if(!vis[x]){
                dfs(adj,st,x,vis);
            }
        }
        vis[curr]=true;
        st.push(curr);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n,vector<int>());
        for(auto x:p){
                adj[x[0]].push_back(x[1]);
        }
        stack<int>st;
        vector<int>res;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,st,i,vis);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};