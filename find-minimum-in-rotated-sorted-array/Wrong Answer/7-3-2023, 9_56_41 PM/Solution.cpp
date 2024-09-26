// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int p=0;
        while(l<r){
            int mid=l+(r-l)/2;
            int next=(mid+1)%(nums.size());
            int prev=(mid+nums.size()-1)%(nums.size());
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next]){
                p=mid;
                return nums[mid];
            }
            else if(nums[l]<=nums[mid]){
                    l=mid+1; }
            else if(nums[mid]<=nums[r]){
                    r=mid;
                }
            }
            return nums[0];
    }
};