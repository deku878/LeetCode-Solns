// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        //2d integers
        //width and height are larger
        sort(e.begin(),e.end());
        int n=e.size();
        vector<int>dp(e.size(),1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(e[i][0]>e[j][0] and e[i][1]>e[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp[dp.size()-1];
    }
};