// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int osp=0;
       int ocp=-prices[0];
       int ncp=-prices[0];
       int nsp=0;
       for(int i=1;i<prices.size();i++){
        if(osp-prices[i]>ocp){
            ncp=osp-prices[i];
        }
        else{
            ncp=ocp;
        }
        if(ocp+prices[i]-fee>osp){
            nsp=ocp+prices[i]-fee;
        }
        else{
            nsp=osp;
        }
        ocp=ncp;
        osp=nsp;
       }
       return osp;
    }
};