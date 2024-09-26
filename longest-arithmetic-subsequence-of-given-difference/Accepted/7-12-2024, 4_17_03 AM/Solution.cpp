// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>dp;
        int maxm=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(dp.find(arr[i]-difference)!=dp.end()){
                dp[arr[i]]=1+dp[arr[i]-difference];
            }
            else{
                dp[arr[i]]=1;
            }
            maxm=max(maxm,dp[arr[i]]);
        }
        return maxm;
    }
};