// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        long long int n=v.size();
        vector<vector<long long int>>dp(n,vector<long long int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                long long int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,v[i]*v[j]*v[k]+(dp[i][k])+(dp[k][j]));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
};