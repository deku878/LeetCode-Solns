// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>pref(nums.size(),0);
        pref[0]=nums[0];
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        map<int,int>mp;
        int count=0;
        mp[0]=1;
        for(int i=0;i<pref.size();i++){
            cout<<pref[i]<<" ";
            count+=mp[pref[i]%k];
             if(pref[i]%k!=0 and nums[i]%k==0 and mp[pref[i]%k]==0){
                count++;
            }
            mp[pref[i]%k]++;
        }
        return count;
    }
};