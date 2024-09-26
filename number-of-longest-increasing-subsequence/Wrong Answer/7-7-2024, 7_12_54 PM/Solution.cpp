// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int maxm=1;
        int cnt=nums.size();
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    if(dp[i]>maxm){
                        cnt=1;
                        maxm=dp[i];
                    }
                    else if(dp[i]==maxm){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};