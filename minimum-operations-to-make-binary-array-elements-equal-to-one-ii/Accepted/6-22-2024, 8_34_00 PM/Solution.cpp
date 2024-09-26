// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int fl=1;
        int ops=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=fl){
                fl=1-fl;
                ops++;
            }
        }
        return ops;
    }
};