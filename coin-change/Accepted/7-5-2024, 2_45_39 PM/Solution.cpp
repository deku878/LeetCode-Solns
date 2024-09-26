// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i]>=0){
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};