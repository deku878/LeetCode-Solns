// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long int maxs=0;
        for(int i=0;i<nums.size();i++){
            maxs+=nums[i];
        }
        long long int reqd=(maxs+target)/2;
        if(target>maxs or (target+maxs)%2!=0 or target<-maxs){
            return 0;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(reqd+1,0));
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=reqd;j++){
                if(nums[i-1]<=j){
                    dp[i][j]+=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size()][reqd];
    }
};