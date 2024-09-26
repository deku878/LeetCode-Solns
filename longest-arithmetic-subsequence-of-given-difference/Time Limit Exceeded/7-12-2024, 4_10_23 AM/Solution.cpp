// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int>dp(arr.size(),1);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if((arr[i]-arr[j])==difference){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxm=max(maxm,dp[i]);
        }
        return maxm;
    }
};