// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=1;
        int n=prices.size();
        //let i be the day we buy and j be the day we sell
        //here we know that a[i]<a[j]
        int maxans=0;
        while(i<n and j<n){
            if(prices[i]>=prices[j]){
                i++;
                j++;
            }
            else{
                maxans=max(maxans,prices[j]-prices[i]);
                j++;
            }
        }
        return maxans;
    }
};