// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int findpar(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=findpar(parent[x]);
    }
    void union1(int x,int y){
        
        int p1=findpar(x);
        int p2=findpar(y);
        if(p1==p2){
            return;
        }
        if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else if(rank[p2]<rank[p1]){
            parent[p2]=p1;
        }
        else{
            parent[p2]=p1;
            rank[p1]++;
        }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>p;
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int p1=findpar(edges[i][0]);
            int p2=findpar(edges[i][1]);
            if(p1==p2){
                p.push_back(edges[i][0]);
                p.push_back(edges[i][1]);
            }
            else{
                union1(edges[i][0],edges[i][1]);
            }
        }
        return p;
    }
};