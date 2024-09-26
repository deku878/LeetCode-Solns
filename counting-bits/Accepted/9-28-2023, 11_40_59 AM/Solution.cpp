// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        int offset=1;
        for(int i=1;i<n+1;i++){
            if(offset*2==i){
                offset=i;
            }
            dp[i]=dp[i-offset]+1;
        }
        return dp;
    }
};