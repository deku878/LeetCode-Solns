// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=dp.size()-1;i++){
            for(int j=1;j<=coins.size();j++){
                if(i+coins[j-1]<=amount){
                dp[i+coins[j-1]]=min(1+dp[i],dp[i+coins[j-1]]);}
            }
        }
        if(dp[amount]!=INT_MAX){
            return dp[amount];
        }
        return -1;
    }
};