// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({k,0});
        vector<long long int>res(n+1,1e9);
        res[k]=0;
        while(!pq.empty()){
            auto o=pq.top();
            pq.pop();
            int p=o.first;
            int w=o.second;
            for(auto t:times){
                if(res[t[0]]+t[2]<res[t[1]]){
                    res[t[1]]=res[t[0]]+t[2];
                    pq.push({t[1],w+res[t[1]]});
                }
            }
        }
        long long int kl=INT_MIN;
        for(int i=1;i<=n;i++){
            if(res[i]==1e9){
                return -1;
            }
            kl=max(kl,res[i]);
        }
        return kl;
    }
};