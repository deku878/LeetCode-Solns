// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        long long int m=matrix.size(),n=matrix[0].size();
        long long int sz=0;
        vector<vector<long long int>> dp(m, vector<long long int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i or !j or matrix[i][j]=='0'){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                sz=max(dp[i][j],sz);
            }
        }
        return sz*sz;
    }
};