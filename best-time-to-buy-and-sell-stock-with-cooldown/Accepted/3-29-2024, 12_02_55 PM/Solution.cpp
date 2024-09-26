// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& a) {
       //let us consider in this case we have 3 states basically
       //old bought state
       //old selling state
       //old cooldown state
       long long int obs=-a[0];
       long long int oss=0;
       long long int ocs=0;
       long long int nbs,nss,ncs;
       for(int i=1;i<a.size();i++){
        if(obs+a[i]>oss){
            nss=obs+a[i];
        }
        else{
            nss=oss;
        }
        if(ocs-a[i]>obs){
            nbs=ocs-a[i];
        }
        else{
            nbs=obs;
        }
        if(ocs>oss){
            ncs=ocs;
        }
        else{
            ncs=oss;
        }
        ocs=ncs;
        oss=nss;
        obs=nbs;
       }
       return oss;
    }
    
};