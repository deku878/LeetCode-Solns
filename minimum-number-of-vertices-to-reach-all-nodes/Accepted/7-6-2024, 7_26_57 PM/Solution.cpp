// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                v.push_back(i);
            }
        }
        return v;
    }
};