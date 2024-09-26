// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        map<int,int>mp;
        vector<vector<int>>dp(a.size(),vector<int>(a.size(),0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<i;j++){
                int need=2*a[j]-a[i];
                dp[j][i]=2;
                if(mp.count(need)!=0){
                    dp[j][i]=max(dp[j][i],1+dp[mp[need]][j]);
                }
            }
            mp[a[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                if(dp[i][j]>=3){
                    cnt+=dp[i][j]-2;
                }
            }
        }
        return cnt;
    }
};