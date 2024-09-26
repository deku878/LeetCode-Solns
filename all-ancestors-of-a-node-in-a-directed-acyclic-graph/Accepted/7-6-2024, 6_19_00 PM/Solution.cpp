// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>deg(n,0);
        vector<vector<int>>adj(n);
        for(auto& e:edges){
            int v=e[0];
            int w=e[1];
            adj[v].push_back(w);
            deg[w]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        vector<set<int>>ancestor(n);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int w:adj[v]){
                ancestor[w].insert(v);
                ancestor[w].insert(ancestor[v].begin(),ancestor[v].end());
                deg[w]--;
                if(deg[w]==0){
                    q.push(w);
                }
            }
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=vector<int>(ancestor[i].begin(),ancestor[i].end());
        }
        return ans;
    }
};