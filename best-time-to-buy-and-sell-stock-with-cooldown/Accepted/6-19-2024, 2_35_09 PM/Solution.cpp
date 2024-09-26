// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int obsp=-a[0];
        int ocsp=0;
        int ossp=0;
        int nbsp=0,ncsp=0,nssp=0;
        for(int i=1;i<a.size();i++){
            if(ocsp-a[i]>obsp){
                nbsp=ocsp-a[i];
            }
            else{
                nbsp=obsp;
            }
            if(obsp+a[i]>ossp){
                nssp=obsp+a[i];
            }
            else{
                nssp=ossp;
            }
            if(ossp>ocsp){
                ncsp=ossp;
            }
            else{
                ncsp=ocsp;
            }
            ossp=nssp;
            ocsp=ncsp;
            obsp=nbsp;
        }
        return nssp;
    }
};