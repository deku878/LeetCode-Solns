// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
            int left = INT_MAX;
     int mid =INT_MAX;

     for ( int i=0;i<nums.size();i++){
        if(nums[i]<left){
          left= nums[i];
        }
        
        if(nums[i]>left && nums[i]<mid){
            mid=nums[i];
        }

        if(nums[i]>mid){
            return true;
        }
        

     }
     return false;
    }
};