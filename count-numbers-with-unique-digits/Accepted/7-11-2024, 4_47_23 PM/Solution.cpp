// https://leetcode.com/problems/count-numbers-with-unique-digits

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        int sum=1;
        for(int i=1;i<=n;i++){
            int pro=9;
            int mu=9;
            for(int j=2;j<i+1;j++){
                pro*=mu;
                mu--;
            }
            dp[i]=sum+pro;
            sum=dp[i];
        }
        return dp[n];
    }
};