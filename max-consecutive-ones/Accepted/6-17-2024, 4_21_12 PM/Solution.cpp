// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cntm=0;
        int mk=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cntm++;
            }
            else{
                mk=max(mk,cntm);
                cntm=0;
            }
        }
        if(cntm>0){
            mk=max(cntm,mk);
        }
        return mk;
    }
};