// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(long long int i=0;i<=amount;i++){
            for(long long int j=0;j<coins.size();j++){
                long long int sum=i+coins[j];
                if(sum<=amount){
                    dp[sum]=min(dp[sum],dp[sum-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};