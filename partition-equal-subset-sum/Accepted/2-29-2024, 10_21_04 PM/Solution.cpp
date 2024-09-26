// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int sum=0;
       
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long int dp[nums.size()+1][sum+1];
        if(sum%2!=0){
            return false;
        }
        else{
            for(int i=0;i<nums.size()+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(j==0){
                        dp[i][j]=1;
                    }
                    else if(i==0){
                        dp[i][j]=0;
                    }
                }
            }
            for(int i=1;i<nums.size()+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};