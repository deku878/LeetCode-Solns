// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        long long int a=lower_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
        long long int b=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
        if(a!=b-1){
            return nums[i];
        }}
        return -1;
    }
};