// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        vector<int>res;
        while(k--){
            auto x=pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};