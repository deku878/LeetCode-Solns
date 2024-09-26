// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        int nb=0;
        map<int,int>mp;
        for(int i=0;i<restricted.size();i++){
            mp[restricted[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.count(i)==0){
                int y=adj[i].size();
                int c=0;
                for(auto j:adj[i]){
                    if(mp.count(j)!=0){
                        c++;
                    }
                }
                if(c==adj[i].size()){
                    mp[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(mp.count(i)==0){
                int y=adj[i].size();
                int c=0;
                for(auto j:adj[i]){
                    if(mp.count(j)!=0){
                        c++;
                    }
                }
                if(c==adj[i].size()){
                    nb++;
                }
            }
            else{
                nb++;
            }
        }
        return n-nb;
    }
};