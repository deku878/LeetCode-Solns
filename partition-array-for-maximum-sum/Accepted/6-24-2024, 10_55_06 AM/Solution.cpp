// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int res(int i,vector<int>&dp,vector<int>&arr,int k){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int len=0;
        int maxm=INT_MIN;
        int sum=INT_MIN;
        for(int r=i;r<min(i+k,(int)arr.size());r++){
            len++;
            maxm=max(maxm,arr[r]);
            sum=max(len*maxm+res(r+1,dp,arr,k),sum);
        }
        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return res(0,dp,arr,k);
    }
};