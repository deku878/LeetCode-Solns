// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        long long int obs=-a[0];
        long long int oss=0;
        long long int res=0;
        long long int nbs,nss;
        for(int i=1;i<a.size();i++){
            if(oss-a[i]>obs){
                nbs=oss-a[i];
            }
            else{
                nbs=obs;
            }
            if(obs+a[i]-fee>oss){
                nss=obs+a[i]-fee;
            }
            else{
                nss=oss;
            }
            obs=nbs;
            oss=nss;
        }
        return oss;
    }
};