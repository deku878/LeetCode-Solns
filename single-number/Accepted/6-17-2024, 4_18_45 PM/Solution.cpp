// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo;
        xo=nums[0];
        for(int i=1;i<nums.size();i++){
            xo^=nums[i];
        }
        return xo;
    }
};