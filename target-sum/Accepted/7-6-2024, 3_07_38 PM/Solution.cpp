// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((target+sum)%2!=0 or target<-1*sum or target>sum){
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(((target+sum)/2)+1,0));
        dp[0][0]=1;
        //sum pata hai total ka
        //ab nikalana hh ki taget ke equal hh present ya nhi
        //sum+target ko div by 2 hona pdega
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=((target+sum)/2);j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0){
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][(target+sum)/2];
    }
};