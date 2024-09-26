// https://leetcode.com/problems/course-schedule-iv

class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    int len=101;
    DSU(){
        parent.resize(len);
        iota(parent.begin(),parent.end(),0);
        size.resize(len,1);
    }
    int find(int v){
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<size[b])
                swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
public:
    void dfs(vector<int>&vis,vector<int>adj[],int node){
        if(vis[node])
            return;
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x])
                dfs(vis,adj,x);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& q) {
        DSU obj;
        vector<int>adj[101];
        for(auto x:pre){
            obj.Union(x[0],x[1]);
            adj[x[0]].push_back(x[1]);
        }
        vector<bool>ans;
        for(auto x:q){
            int a=obj.find(x[0]);
            int b=obj.find(x[1]);
            if(a!=b)
                ans.push_back(false);
            else{
                vector<int>vis(101,false);
                dfs(vis,adj,x[0]);
                if(vis[x[1]])
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }
        return ans;
    }
};
