// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& a) {
        long long int obs=-a[0];
        long long int oss=0;
        long long int nss,nbs;
        for(int i=1;i<a.size();i++){
            if(obs+a[i]>oss){
                nss=obs+a[i];
            }
            else{
                nss=oss;
            }
            if(oss-a[i]>obs){
                nbs=oss-a[i];
            }
            else{
                nbs=obs;
            }
            obs=nbs;
            oss=nss;
        }
        return oss;
    }
};