// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        vector<int>suffix(prices.size(),0);
        suffix[prices.size()-1]=prices[prices.size()-1];
        for(int i=suffix.size()-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],prices[i]);
        }
        for(int i=0;i<prices.size();i++){
            profit=max(profit,suffix[i]-prices[i]);
        }
        return profit;
    }
};