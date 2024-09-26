// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& a) {
        //what to do in this case
        //pehle do variable define krne hh
        //buying rate and selling rate
        int n=a.size();
        int br=a[0];
        int sr=a[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){
                sr=a[i];
            }
            else{
                profit+=sr-br;
                sr=a[i];
                br=a[i];
            }
        }
        if(sr>br){
            profit+=sr-br;
        }
        return profit;
    }
};