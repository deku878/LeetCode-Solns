// https://leetcode.com/problems/filling-bookcase-shelves

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        //books i thickness,height
        //shelfwidth
        //total width shelfwidth
        // is a variation of knapsack
        vector<int>dp(books.size()+1,INT_MAX);
        dp[0]=0;
        for(int j=1;j<=books.size();j++){
            int curw=0;
            int curh=0;
            int k=1;
            while(k<=j){
                curh=max(curh,books[j-k][1]);
                curw+=books[j-k][0];
                if(curw>shelf_width){
                    break;
                }
                dp[j]=min(dp[j],dp[j-k]+curh);
                k++;
            }
        }
        return dp[books.size()];
    }
};