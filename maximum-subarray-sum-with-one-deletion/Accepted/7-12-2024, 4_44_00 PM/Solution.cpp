// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion

class Solution {
public:
       int maximumSum(vector<int>& arr) {
        vector<vector<long long int>>dp(arr.size(),vector<long long int>(2,0));
        dp[0][0]=INT_MIN;
        dp[0][1]=arr[0];
        long long int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            long long int h=arr[i];
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]+h);
            dp[i][1]=max(h,dp[i-1][1]+h);
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};