// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,0));
        int n=nums.size();
        for(int i=0;i<=nums.size();i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0){
                    dp[i][j]=dp[i][j]|dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
};