// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int pl(int i,vector<int>&dp,vector<int>&a,int k){
        if(i==dp.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int len=0;
        int maxm=INT_MIN;
        int su=INT_MIN;
        for(int r=i; r < min(i+k,(int)a.size());r++){
            len++;
            maxm=max(maxm,a[r]);
            su=max(len*maxm+pl(r+1,dp,a,k),su);
        }
        return dp[i]=su;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return pl(0,dp,arr,k);
    }
};