// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int atmost(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        int io=0;
        int j=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            io+=i-j+1;
        }
        return io;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};