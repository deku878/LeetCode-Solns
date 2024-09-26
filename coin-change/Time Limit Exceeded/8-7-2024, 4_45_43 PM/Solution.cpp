// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coin(vector<int>&c,int amount,int n){
        if(amount==0){
            return 0;
        }
        else if(amount<0 or n<=0){
            return INT_MAX-1;
        }

        if(c[n-1]<=amount){
            int pick=coin(c,amount-c[n-1],n);
            int notpick=coin(c,amount,n-1);
            return min(1+pick,notpick);
        }
        int no=coin(c,amount,n-1);
        return no;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res= coin(coins,amount,coins.size());
        if(res==INT_MAX-1){
            return -1;
        }
        return res;
    }
};