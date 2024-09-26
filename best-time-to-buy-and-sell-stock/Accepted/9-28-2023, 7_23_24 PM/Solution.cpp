// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0;//to buy
      int j=1;//to sell
      int maxprice=0;
      int n=prices.size();
      while(j<n){
         maxprice=max(maxprice,prices[j]-prices[i]);
         if(prices[i]>=prices[j]){
             i=j;
             j++;
         }
         else{
             j++;
         }
      }
      return maxprice;
    }
};