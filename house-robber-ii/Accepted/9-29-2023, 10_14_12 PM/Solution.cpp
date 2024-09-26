// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob1(vector<int>& nums) {
        vector<long long int>dp(nums.size());
        if(nums.size()<2){
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>p(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++){
            p[i]=nums[i];
        }
        vector<int>c(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++){
            c[i]=nums[i+1];
        }
        int m=rob1(c);
        int n=rob1(p);
        return max(m,n);
    }
};