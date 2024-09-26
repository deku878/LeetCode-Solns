// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string x,string y,int n,int m){
        if(n<=0 or m<=0){
            return 0;
        }
        if(x[n-1]==y[m-1]){
            return 1+lcs(x,y,n-1,m-1);
        }
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};