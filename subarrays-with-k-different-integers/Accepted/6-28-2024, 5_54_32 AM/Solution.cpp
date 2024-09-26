// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int cnts(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        int i=0;
        int j=0;
        map<int,int>mp;
        int cnt=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cnts(nums,k)-cnts(nums,k-1);
    }
};