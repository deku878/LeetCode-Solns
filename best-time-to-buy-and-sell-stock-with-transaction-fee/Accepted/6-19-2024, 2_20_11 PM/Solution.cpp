// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int ossp=0;
        int obsp=-a[0];
        int nbsp=-a[0];
        int nssp=0;
        for(int i=1;i<a.size();i++){
            if(obsp+a[i]-fee>ossp){
                nssp=obsp+a[i]-fee;
            }
            else{
                nssp=ossp;
            }
            if(ossp-a[i]>obsp){
                nbsp=ossp-a[i];
            }
            else{
                nbsp=obsp;
            }
            ossp=nssp;
            obsp=nbsp;
        }
    return ossp;
    }
};