// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>suff(prices.size(),INT_MIN);
        suff[0]=prices[prices.size()-1];
        for(int i=1;i<prices.size();i++){
            suff[i]=max(suff[i-1],prices[prices.size()-i-1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<prices.size()-1;i++){
            ans=max(ans,suff[prices.size()-i-2]-prices[i]);
        }
        if(ans<=0){
            return 0;
        }
        return ans;
    }
};