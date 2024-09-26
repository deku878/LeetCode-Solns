// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};