// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>dp(s.size()+1,0);
        int cnt_b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                dp[i+1]=dp[i];
                cnt_b++;
            }
            else{
                dp[i+1]=min(dp[i]+1,cnt_b);
            }
        }
        return dp[s.size()];
    }
};