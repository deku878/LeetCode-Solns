// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        if(nums.size()==1 or nums.size()==2){
            return -1;
        }
        else{
        while(l<=r){
            int mid=l+(r-l)/2;
            int prev=(mid+nums.size()-1)%(nums.size());
            int next=(mid+1)%(nums.size());
            if(nums[mid]>nums[prev] and nums[mid]>nums[next]){
                return mid;
            }
            else if(nums[mid]<nums[r]){
                r=mid-1;
            }
            else if(nums[mid<nums[l]]){
                l=mid+1;
            }
        }}
        return -1;
    }
};