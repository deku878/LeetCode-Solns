// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>j=nums;
        for(int i=0;i<nums.size();i++){
            j[(i+k)%nums.size()]=nums[i];
        }
        nums=j;
    }
};