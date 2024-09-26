// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[r] and nums[l]==nums[mid]){
                l++;
                r--;
                continue;
            }
            else if(nums[l]<=nums[mid]){
                l=mid+1;
            }
            else if(nums[mid]<=nums[r]){
                r=mid-1;
            }
        }
        return false;
    }
};