// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        long long int n=nums.size();
        vector<long long int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp[dp.size()-1];
    }
};