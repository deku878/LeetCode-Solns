// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, long long int amount) {
        vector<long long int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(long long int i=0;i<=dp.size()-1;i++){
            for(long long int j=1;j<=coins.size();j++){
                long long int b=i+coins[j-1];
                if(b<=amount){
                dp[i+coins[j-1]]=min(1+dp[i],dp[i+coins[j-1]]);}
            }
        }
        if(dp[amount]!=INT_MAX){
            return dp[amount];
        }
        return -1;
    }
};