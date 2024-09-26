// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[r]){
                r=mid-1;
            }
            else if(nums[mid<nums[l]]){
                l=mid+1;
            }
        }
        return -1;
    }
};