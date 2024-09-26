// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int count=0;
       for(int i=0;i<nums.size();i++){
           int j=i+1;
           map<int,int>mp;
           mp[nums[i]]++;
           if(mp.size()==k){
               count++;
           }
           while(j<nums.size()){
               mp[nums[j]]++;
               if(mp.size()==k){
                   count++;
               }
               j++;
           }
       }
       return count;
    }
};