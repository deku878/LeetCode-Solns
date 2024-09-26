// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mp;
       int sum=0;
       int cnt=0;
       mp[0]=1;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        cnt+=mp[sum-k];
        mp[sum]++;
       }
       return cnt;
    }
};