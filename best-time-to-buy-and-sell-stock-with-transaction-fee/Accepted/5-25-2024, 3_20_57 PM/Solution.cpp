// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
       int obsp=-a[0];
       int nbsp=0,ossp=0,nssp=0;
       for(int i=1;i<a.size();i++){
        nbsp=0;
        nssp=0;
        if(ossp-a[i]>obsp){
            nbsp=ossp-a[i];
        }
        else{
            nbsp=obsp;
        }
        if(obsp+a[i]-fee>ossp){
            nssp=obsp+a[i]-fee;
        }
        else{
            nssp=ossp;
        }
        ossp=nssp;
        obsp=nbsp;
       }
       return ossp;
    }
};