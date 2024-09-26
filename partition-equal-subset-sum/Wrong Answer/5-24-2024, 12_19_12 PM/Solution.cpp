// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<long long int>>dp(nums.size()+1,vector<long long int>(sum+1,0));
        for(int i=0;i<sum+1;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<nums.size()+1;i++){
            dp[i][0]=1;
        }
        if(sum%2!=0){
            return false;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i][j-nums[i-1]];}
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};