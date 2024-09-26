// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coin(vector<int>&c,int amount,int n,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        else if(amount<0 or n<=0){
            return INT_MAX-1;
        }
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        if(c[n-1]<=amount){
            int pick=coin(c,amount-c[n-1],n,dp);
            int notpick=coin(c,amount,n-1,dp);
            return dp[amount][n]=min(1+pick,notpick);
        }
        int no=coin(c,amount,n-1,dp);
        return dp[amount][n]=no;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        int res= coin(coins,amount,coins.size(),dp);
        if(res==INT_MAX-1){
            return -1;
        }
        return res;
    }
};