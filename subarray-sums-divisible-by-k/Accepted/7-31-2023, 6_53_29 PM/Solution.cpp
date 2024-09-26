// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>pf(nums.size());
        nums[0]=(k+nums[0]%k)%k;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            nums[i]=(k+nums[i]%k)%k;
        }
        map<int,int>mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};