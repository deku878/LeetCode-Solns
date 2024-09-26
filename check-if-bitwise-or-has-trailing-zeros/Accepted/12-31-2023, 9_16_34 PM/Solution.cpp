// https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        long long int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                count++;
            }
        }
        return count>=2;
    }
};