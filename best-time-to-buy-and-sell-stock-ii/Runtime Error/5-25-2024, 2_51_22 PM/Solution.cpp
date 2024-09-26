// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int br=0,sr=0;
        br=p[0],sr=p[0];
        long long int profit=0;
        for(int i=1;i<p.size();i++){
            if(p[i]<p[i-1]){
                profit+=sr-br;
                sr=p[i];
                br=p[i];
            }
            else{
                sr=p[i];
            }
        }
        if(p[p.size()-1]>p[p.size()-2]){
        profit+=sr-br;}
        return profit;
    }
};