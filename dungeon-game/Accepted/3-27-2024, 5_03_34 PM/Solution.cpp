// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m = d.size(), n = d[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;    //the DOWN and RIGHT cells from the end cell (As explained above, the minimum cost needed to move to the next cells)
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {    //start filling from the bottom-right corner 
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - d[i][j]);     //We need to see that the health point doesn't drop to 0 or low. Hence --> max(1, ...). Now this "..." is the strength that's needed for this cell + that needed to travel to the next cell.  //d[i][j] is the strength provided by this cell and the strength needed to travel to the next cell is min(dp[i+1][j], dp[i][j+1])
            }
        }
        return dp[0][0];    //return the health needed in the first cell
    }
};
