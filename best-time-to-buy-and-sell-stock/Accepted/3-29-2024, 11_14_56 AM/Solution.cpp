// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>pref(prices.size(),0),suff(prices.size(),0);
        suff[0]=prices[prices.size()-1];
        for(int i=1;i<prices.size();i++){
            suff[i]=max(prices[prices.size()-i-1],suff[i-1]);
        }
        reverse(suff.begin(),suff.end());
        long long int ans=0;
        for(int i=0;i<prices.size();i++){
            long long int p=suff[i]-prices[i];
            ans=max(ans,p);
        }
        return ans;
    }
};