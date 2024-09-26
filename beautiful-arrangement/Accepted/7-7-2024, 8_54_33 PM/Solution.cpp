// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int countArrangement(int n) {
        int lim=1<<n;
        vector<int> dp(lim, 0);
        dp[0]=1;
        for(int i=0;i<lim;i++)
        {
            int pos=__builtin_popcount(i);
            for(int j=0;j<n;j++)
            {
             if((i&(1<<j))==0)  
             {
                 int newMask=i|(1<<j);
                 if(((pos+1)%(j+1))==0 || ((j+1)%(pos+1))==0)
                 dp[newMask]=dp[newMask]+dp[i];
             } 
            }
        }
        return dp[(1<<n)-1];
    }
};
