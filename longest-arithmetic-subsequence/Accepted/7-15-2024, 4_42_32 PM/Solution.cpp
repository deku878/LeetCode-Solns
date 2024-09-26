// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        map<int,int>mp;
        vector<vector<long long int>>dp(nums.size(),vector<long long int>(nums.size(),2));
        dp[0][0]=1;
        long long int maxm=2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int need=2*nums[i]-nums[j];
                dp[i][j]=2;
                if(mp.find(need)!=mp.end()){
                    dp[i][j]=max(dp[i][j],dp[mp[need]][i]+1);
                }
                maxm=max(maxm,dp[i][j]);
            }
            mp[nums[i]]=i;
        }
        return maxm;
    }
};