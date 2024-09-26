// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obp=-prices[0];
        int osp=0;
        int nbp=0;
        int nsp=0;
        for(int i=1;i<prices.size();i++){
            if((osp-prices[i])>obp){
                nbp=osp-prices[i];
            }
            else{
                nbp=obp;
            }
            if(obp+prices[i]-fee>osp){
                nsp=obp+prices[i]-fee;
            }
            else{
                nsp=osp;
            }
            osp=nsp;
            obp=nbp;
        }
        return osp;
    }
};