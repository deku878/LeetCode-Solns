// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1;
        int r=nums.size()-2;
        int n=nums.size();
        if(nums.size()==1){
            return 0;
        }
        else if(nums[0]>nums[1]){
            return 0;
        }
        else if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        else{
        while(l<=r){
            int mid=l+(r-l)/2;
            int prev=(mid-1);
            int next=(mid+1);
            if(nums[mid]>nums[prev] and nums[mid]>nums[next]){
                return mid;
            }
            else if(nums[mid]>nums[mid+1]){
                r=mid-1;
            }
            else if(nums[mid]>nums[mid-1]){
                l=mid+1;
            }
        }}
        return -1;
    }
};