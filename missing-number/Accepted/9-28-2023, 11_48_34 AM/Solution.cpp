// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int p=nums[nums.size()-1];
        int realsum=(p)*(p+1)/2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int missing=realsum-sum;
        if(missing==0 and nums[0]==0){
            return p+1;
        }
        if(missing==0 and nums[0]!=0){
            return 0;
        }
        return missing;
    }
};