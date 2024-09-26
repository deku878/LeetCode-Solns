// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>pref(prices.size());
        vector<int>suff(prices.size());
        suff=prices;
        pref=prices;
        for(int i=prices.size()-2;i>=0;i--){
            suff[i]=max(prices[i],suff[i+1]);
        }
        for(int i=1;i<prices.size();i++){
            pref[i]=min(pref[i-1],prices[i]);
        }
        int lol=INT_MIN;
        for(int i=0;i<prices.size();i++){
            lol=max(lol,suff[i]-pref[i]);
        }
        //7 1 1 1 1 1 1
        //7 6 6 6 6 6 4
        return lol;
    }
};