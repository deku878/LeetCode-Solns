// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        vector<vector<int>>dp1(m+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(s1[i-1]==s3[j-1]){
                    dp[i][j]=max({1+dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                if(s2[i-1]==s3[j-1]){
                    dp1[i][j]=1+dp1[i-1][j-1];
                }
                else{
                    dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
                }
            }
        }
        int lcs1=dp[n][k];
        int lcs2=dp1[m][k];
        if((lcs1+lcs2)<s3.size() or lcs1!=s1.size() or lcs2!=s2.size()){
            return false;
        }
        return true;
    }
};