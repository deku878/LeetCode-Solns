// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        queue<int>q;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                res++;
            }
        }
        vector<int>res1;
        while(!q.empty()){
            auto o=q.front();
            q.pop();
            res1.push_back(o);
            for(auto y:adj[o]){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                    res++;
                }
            }
        }
        if(res==n){
            reverse(res1.begin(),res1.end());
            return res1;
        }
        return {};
    }
};