// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
        map<int,int>mp;
        int maxm=INT_MIN;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int need=arr[j]-arr[i];
                dp[i][j]=2;
                if(mp.find(need)!=mp.end()){
                    if(mp[need]>i){
                        dp[i][j]=max(dp[i][j],dp[i][mp[need]]+1);
                    }
                    else{
                        dp[i][j]=max(dp[i][j],dp[mp[need]][i]+1);
                    }
                }
                maxm=max(maxm,dp[i][j]);
            }
            mp[arr[i]]=i;
        }
        if(maxm!=2){
        return maxm;}
        return 0;
    }
};