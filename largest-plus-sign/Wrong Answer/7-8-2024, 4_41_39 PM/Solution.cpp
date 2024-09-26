// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& m) {
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<vector<int>>mines(n,vector<int>(n,1));
        for(int i=0;i<m.size();i++){
            mines[m[0][0]][m[0][1]]=0;
        }
        for(int i=0;i<n;i++){
            if(mines[0][i]==1){
            dp[0][i]=1;}
        }
        for(int j=0;j<n;j++){
            if(mines[j][0]==1){
            dp[j][0]=1;}
        }
        int maxm=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(mines[i][j]==1){
                    if(i+1<n and i-1>=0 and j+1<n and j-1>=0){
                        dp[i][j]=1+min({mines[i+1][j],mines[i-1][j],mines[i][j+1],mines[i][j-1]});
                    }
                    else{
                        dp[i][j]=1;
                    }
                    maxm=max(maxm,dp[i][j]);
                }
            }
            mines=dp;
        }
        return maxm;
    }
};