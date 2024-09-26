// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--){
            for(auto w:wordDict){
                if(s.size()-i>=w.size() and s.substr(i,w.size())==w){
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};