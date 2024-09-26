// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int i=0;
        int j=0;
        int count=0;
        map<int,int>mp;
        int n=nums.size();
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]<=0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            count+=abs(i-j)+1;
            i++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmost(nums,k)-atmost(nums,k-1);
    }
};