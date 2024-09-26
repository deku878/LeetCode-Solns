// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        int ans=INT_MIN;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(auto k:adj[i]){
                ans=max(ans,indegree[k]+indegree[i]-1);
                vis[k]=true;
            }
            for(int j=0;j<n;j++){
                if(!vis[j] and i!=j){
                    ans=max(ans,indegree[j]+indegree[i]);
                }
                if(vis[j]){
                    vis[j]=false;
                }
            }
        }
        return ans;
    }
};