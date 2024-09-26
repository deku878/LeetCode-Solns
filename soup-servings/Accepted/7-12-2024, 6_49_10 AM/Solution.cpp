// https://leetcode.com/problems/soup-servings

class Solution {
public:
    double soupServings(int n) {
                if(n > 4800) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1, 0));

        dp[0][0] = 0.5;
        for(int i=1; i<=n; i++){
            dp[0][i] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                double x = 0.25 * dp[max(0, i-100)][j];
                double y = 0.25 * dp[max(0, i-75)][max(0, j-25)];
                double z = 0.25 * dp[max(0, i-50)][max(0, j-50)];
                double w = 0.25 * dp[max(0, i-25)][max(0, j-75)];
               
                dp[i][j] = x + y + w + z;
            }
        }
        return dp[n][n];

    }
};