// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int sum=0;
        long long int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<0){
                sum=0;
            }
            else{
                 sum+=nums[i];
            }
            maxsum=max(maxsum,sum);
        }
        if(maxsum==0){
            return *std::max_element(nums.begin(),nums.end());
        }
        return maxsum;
    }
};