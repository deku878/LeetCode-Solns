// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int p=1e4;
        vector<int>count(p+1,0);
        vector<int>dp(p+1,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        dp[0]=0;
        dp[1]=count[1];
        for(int i=2;i<dp.size();i++){
            int ntpick=dp[i-1];
            int pick=count[i]*i+dp[i-2];
            dp[i]=max(ntpick,pick);
        }
        return dp[dp.size()-1];
    }
};