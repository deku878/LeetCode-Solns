// https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        // 3 lane road of length n -> 0 se n tak ke points hh
        // array of length n+1->obs[i] desc obstacle on pt i
        //obs[i]==0
        vector<vector<long long int>>dp(obstacles.size(),vector<long long int>(3,INT_MAX));
        int minm=0;
        dp[0][1]=0;
        int n=obstacles.size();
        for(int i=1;i<n;i++){
            if(obstacles[i]==1){
                 if(obstacles[i-1]!=3){
                dp[i][2]=min(dp[i-1][2],dp[i-1][0]+1);}
                 if(obstacles[i-1]!=2){
                dp[i][1]=min(dp[i-1][1],dp[i-1][0]+1);}
            }
            else if(obstacles[i]==2){
                 if(obstacles[i-1]!=3){
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]+1);}
                 if(obstacles[i-1]!=1){
                dp[i][0]=min(dp[i-1][0],dp[i-1][1]+1);}
            }
            else if(obstacles[i]==3){
                if(obstacles[i-1]!=2){
                dp[i][1]=min(dp[i-1][1],dp[i-1][2]+1);}
                if(obstacles[i-1]!=1){
                dp[i][0]=min(dp[i-1][0],dp[i-1][2]+1);}
            }
            else{
                dp[i][2]=dp[i-1][2];
                dp[i][1]=dp[i-1][1];
                dp[i][0]=dp[i-1][0];
            }
            minm=min({dp[i][0],dp[i][1],dp[i][2]});
        }
        return minm;
    }
};