// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       long long int x=1<<16;
       x+=2;
       vector<int>dp(x,-1);
       dp[0]=0;
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
       }
       if(sum%k!=0){
        return false;
       }
       sum/=k;
       for(int mask=0;mask<(1<<nums.size());mask++){
        if(dp[mask]==-1){
            continue;
        }
        for(int i=0;i<nums.size();i++){
            if(!(mask&(1<<i)) and dp[mask]+nums[i]<=sum){
                dp[mask|(1<<i)]=(dp[mask]+nums[i])%sum;
            }
        }
       }
       return dp[(1<<nums.size())-1]==0;
    }
};