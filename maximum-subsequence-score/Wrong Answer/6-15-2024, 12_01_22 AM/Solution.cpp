// https://leetcode.com/problems/maximum-subsequence-score

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long int sum=0;
        long long int ans=0;
        vector<pair<int,int>>a;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums1.size();i++){
            a.push_back({nums2[i],nums1[i]});
        }
        sort(a.begin(),a.end(),greater<pair<int,int>>());

        long long int res=INT_MIN;
        for(int i=0;i<a.size();i++){
            pq.push(a[i].second);
            sum+=a[i].second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            else if(pq.size()==k){
                res=max(res,sum*a[i].first);
            }
        }
        return res;
    }
};