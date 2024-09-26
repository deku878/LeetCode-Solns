// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pr=0;
        int rpr=0;
        vector<int>su(prices.size(),0);
        su[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            su[i]=max(prices[i],su[i+1]);
        }
        for(int i=0;i<prices.size();i++){
            pr=max(pr,su[i]-prices[i]);
        }
        return pr;
    }
};