// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==x){
                return true;
            }
            if(nums[lo]==nums[mid] and nums[mid]==nums[hi]){
                lo++;
                hi--;
            }
            else if(nums[mid]<=nums[hi]){
                if(nums[mid]<=x and nums[hi]>=x){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=x and nums[mid]>=x){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
        }
        return false;
    }
};