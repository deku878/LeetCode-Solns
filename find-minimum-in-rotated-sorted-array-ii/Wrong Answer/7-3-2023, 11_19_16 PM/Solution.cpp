// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]==nums[mid] and nums[r]==nums[mid] ){
                l++;
                r--;
                continue;
            }
            else if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<=nums[r]){
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};