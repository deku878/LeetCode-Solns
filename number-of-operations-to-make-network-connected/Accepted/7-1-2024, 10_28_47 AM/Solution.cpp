// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
vector<int>rank,parent;
public:
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void union1(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(p1==p2){
            return;
        }
        if(rank[p2]<rank[p1]){
            parent[p2]=p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else{
            parent[p1]=p2;
            rank[p2]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& x) {
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int ex=0;
        for(int i=0;i<x.size();i++){
                if(find(x[i][0])==find(x[i][1])){
                    ex++;
                }
                else{
                    union1(x[i][0],x[i][1]);
                }
        }
        int cnc=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i){
                cnc++;
            }
        }
        if(ex>=cnc-1){
            return cnc-1;
        }
        return -1;
    }
};