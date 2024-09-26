// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        long long int n=nums1.size();
        long long int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int prod=nums1[i-1]*nums2[j-1];
                dp[i][j]=prod+max(0,dp[i-1][j-1]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};