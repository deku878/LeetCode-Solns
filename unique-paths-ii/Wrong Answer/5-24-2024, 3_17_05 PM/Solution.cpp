// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(o[i][0]!=1){
                dp[i][0]=1;
            }
            else{
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(o[0][i]!=1){
                dp[0][i]=1;
            }
            else{
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(o[i][j]!=1){
                int ans1=dp[i-1][j];
                int ans2=dp[i][j-1];
                int ansr=ans1+ans2;
                if(ansr!=0){
                    dp[i][j]=ansr;
                }
                else{
                    dp[i][j]=0;
                }}
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n-1][n-1];
    }
};