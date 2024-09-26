// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int obsp,ossp,ocsp;
        obsp=-a[0];
        ossp=0;
        ocsp=0;
        for(int i=1;i<a.size();i++){
            int nbsp=0,nssp=0,ncsp=0;
            if(ocsp-a[i]>obsp){
                nbsp=ocsp-a[i];
            }
            else{
                nbsp=obsp;
            }
            if(ossp>ocsp){
                ncsp=ossp;
            }
            else{
                ncsp=ocsp;
            }
            if(obsp+a[i]>ossp){
                nssp=obsp+a[i];
            }
            else{
                nssp=ossp;
            }
            ossp=nssp;
            ocsp=ncsp;
            obsp=nbsp;
        }
        return ossp;
    }
};