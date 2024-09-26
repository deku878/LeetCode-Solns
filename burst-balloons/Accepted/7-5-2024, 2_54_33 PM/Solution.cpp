// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int pre(vector<int>&nums,vector<vector<int>>&dp,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            ans=max(nums[i-1]*nums[k]*nums[j+1]+pre(nums,dp,i,k-1)+pre(nums,dp,k+1,j),ans);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return pre(nums,dp,1,n);
    }
};