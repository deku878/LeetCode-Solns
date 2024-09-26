// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        for(int i=0;i<n;i++){
            cout<<indegree[i]<<" ";
        }
        
        queue<int>q;
        int cnt=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                v.push_back(i);
                cnt++;
            }
        }
        cout<<endl;
        while(!q.empty()){ 
            auto x=q.front();
            q.pop();
            for(auto y:adj[x]){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                    v.push_back(y);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        if(cnt!=n){
            vector<int>u;
            return u;
        }
        return v;
    }
};