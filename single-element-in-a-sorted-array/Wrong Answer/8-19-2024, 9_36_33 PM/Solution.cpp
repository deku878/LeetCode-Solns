// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=1;
        int hi=nums.size()-2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid+1] and nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(mid%2!=0){
                //odd
                if(nums[mid]==nums[mid+1]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
        }
        return -1;
    }
};