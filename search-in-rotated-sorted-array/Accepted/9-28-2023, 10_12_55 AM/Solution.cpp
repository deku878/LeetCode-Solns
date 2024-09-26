// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                if(target>nums[mid] or target<nums[l]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            else{
                if(target<nums[mid] or nums[r]<target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};