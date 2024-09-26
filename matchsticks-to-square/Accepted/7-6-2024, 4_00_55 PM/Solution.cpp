// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(1<<n,-1);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%4!=0){
            return false;
        }
        int target=sum/4;
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==-1){
                continue;
            }
            for(int i=0;i<n;i++){
                if(!(mask & (1<<i)) && (dp[mask]+nums[i]<=target)){
                    dp[mask|(1<<i)]=(dp[mask]+nums[i])%target;
                }
            }
        }
        return dp[(1<<n)-1]==0;
    }
};