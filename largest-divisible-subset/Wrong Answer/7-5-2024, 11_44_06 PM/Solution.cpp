// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=0;i<nums.size();i++){
             vector<int>dp;
            dp.push_back(nums[i]);
            for(int j=0;j<i;j++){
                if((nums[i])%(nums[j])==0){
                dp.push_back(nums[j]);}
            }
            if(res.size()<dp.size()){
                res=dp;
            }
        }
        return res;
    }
};