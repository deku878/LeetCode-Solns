// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //pick and not pick wali condition aajaegi
                int pick=0;
                if(s[i-1]==t[j-1]){
                    pick=dp[i-1][j-1];
                }
                int notpick=dp[i-1][j];
                dp[i][j]=pick+notpick;
            }
        }
        return dp[n][m];
    }
};