// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>pref(nums.size(),0);
        pref[0]=nums[0];
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        map<int,int>mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.count(pref[i]-k)!=0){
                ans+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return ans;
    }
};