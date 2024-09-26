// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int cways(int amount,vector<int>&coins,int n){
        if(amount==0){
            return 1;
        }
        if(amount<0 or n<=0){
            return 0;
        }
        if(coins[n-1]<=amount){
            int pick=cways(amount-coins[n-1],coins,n);
            int notpick=cways(amount,coins,n-1);
            return pick+notpick;
        }
        int no=cways(amount,coins,n-1);
        return no;
    }
    int change(int amount, vector<int>& coins) {
        return cways(amount,coins,coins.size());
    }
};