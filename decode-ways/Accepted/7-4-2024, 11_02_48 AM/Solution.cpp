// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(stoi(s.substr(i,1))>=1 and stoi(s.substr(i,1))<=9){
            dp[i]=dp[i]+dp[i+1];}
            if(i<=s.size()-2){
                if(stoi(s.substr(i,2))>=10 and stoi(s.substr(i,2))<=26){
                    dp[i]=dp[i]+dp[i+2];
                }
            }
        }
        return dp[0];
    }
};