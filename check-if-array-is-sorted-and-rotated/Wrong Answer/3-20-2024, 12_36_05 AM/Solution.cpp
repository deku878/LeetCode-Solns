// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>nums1=nums;
        sort(nums1.begin(),nums1.end());
        long long int in=INT_MIN;
        for(long long int i=0;i<nums.size();i++){
            if(nums1[nums1.size()-1]==nums[i]){
                in=max(in,i);
            }
        }
        bool check=true;
        if(in==0){
            for(int i=1;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    check=false;
                }
            }
        }
        else if(in==nums.size()-1){
            for(int i=nums.size()-1;i>0;i--){
                if(nums[i]<nums[i-1]){
                    check=false;
                }
            }
        }
        else{
            for(int i=0;i<in;i++){
                if(nums[i]>nums[i+1]){
                    check=false;
                }
            }
            for(int i=in+1;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1] and i+1!=nums.size()){
                    check=false;
                }
            }
        }
        return check;
    }
};