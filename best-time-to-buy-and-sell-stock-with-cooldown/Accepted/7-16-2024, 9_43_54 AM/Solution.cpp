// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int obp=-prices[0];
        int ocp=0;
        int osp=0;
        int ncp=0;
        int nsp=0;
        int nbp=0;
        for(int i=1;i<prices.size();i++){
            if(ocp-prices[i]>obp){
                nbp=ocp-prices[i];
            }
            else{
                nbp=obp;
            }
            if(obp+prices[i]>osp){
                nsp=obp+prices[i];
            }
            else{
                nsp=osp;
            }
            if(osp>ocp){
                ncp=osp;
            }
            else{
                ncp=ocp;
            }
            ocp=ncp;
            osp=nsp;
            obp=nbp;
        }
        return osp;
    }
};