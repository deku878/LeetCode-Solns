// https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long int p=nums.size()-1;
        long long int sum=nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            if(sum>=nums[i-1]){
                sum+=nums[i-1];
            }
            else{
                sum=nums[i-1];
            }
        }
        return sum;
    }
};