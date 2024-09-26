// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        //directed graph me cycle nikalni hh isme bas
       vector<int>indegree(n);
       vector<vector<int>>adj(n,vector<int>());
       for(auto x:pr){
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
       }
       int cnt=0;
       queue<int>q;
       for(int i=0;i<n;i++){
        if(indegree[i]==0){
            cnt++;
            q.push(i);
        }
       }
       while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto y:adj[x]){
            indegree[y]--;
            if(indegree[y]==0){
                cnt++;
                q.push(y);
            }
        }
       }
       return cnt==n;
    }
};