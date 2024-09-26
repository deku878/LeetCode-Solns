// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxs=0;
        bool check=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                check=true;
            }
        }
        if(!check){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<0){
                maxs=max(maxs,sum);
                sum=0;
            }
            else{
                sum+=nums[i];
                maxs=max(maxs,sum);
            }
            maxs=max(maxs,sum);
        }
        return maxs;
    }
};