// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int sm=-1;
        int mm=-1;
        int lm=-1;
        for(int i=0;i<nums.size();i++){
            if(sm==-1){
                sm=nums[i];
            }
            else if(mm==-1 and sm<nums[i]){
                mm=nums[i];
            }
            else if(lm==-1 and mm<nums[i]){
                lm=nums[i];
            }
            if(mm>nums[i] and nums[i]>sm){
                mm=nums[i];
            }
        }
        if(sm==-1 or mm==-1 or lm==-1){
            return false;
        }
        return true;
    }
};