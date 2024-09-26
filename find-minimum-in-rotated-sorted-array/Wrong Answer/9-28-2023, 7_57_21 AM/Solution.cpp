// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=nums[0];
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            if(nums[l]<nums[r]){
                res=min(res,nums[l]);
                break;
            }
            int m=l+(r-l)/2;
            if(nums[m]>=nums[l]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return res;
    }
};