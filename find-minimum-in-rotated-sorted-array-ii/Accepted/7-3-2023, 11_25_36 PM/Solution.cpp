// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
         int n=nums.size();
       int low=0;
       int high=n-1;
       int ans=INT_MAX;

       while(low<=high){

           int mid=low+(high-low)/2;

           if(nums[low]==nums[high]){
               ans=min(nums[low],ans);
               low++;

           }
          else if(nums[mid]<=nums[high]){
               ans=min(nums[mid],ans);
               high=mid-1;
           }
           else{
               ans=min(nums[low],ans);
               low=mid+1;
           }
           
       }

       return ans;
    }
};