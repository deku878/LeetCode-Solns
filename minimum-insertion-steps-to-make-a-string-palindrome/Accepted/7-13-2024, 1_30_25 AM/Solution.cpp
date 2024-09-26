// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs=dp[s.size()][t.size()];
        return s.size()-lcs;
    }
};