// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int n, m;
    int target;
    int dp[71][5000]; 
    int solve(int row, int sum, vector<vector<int>>& mat){
        if(row==n){
            return abs(sum-target);
        }
        if(dp[row][sum]!=-1){
            return dp[row][sum];
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,solve(row+1,sum+mat[row][j],mat));
        }
        return dp[row][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int t) {
        n = mat.size();
        m = mat[0].size();
        target = t;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, mat);
    }
};