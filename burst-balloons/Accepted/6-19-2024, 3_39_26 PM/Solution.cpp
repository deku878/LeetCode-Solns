// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int res(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minm=INT_MIN;
        for(int k=i;k<=j;k++){
            int x=(a[i-1]*a[k]*a[j+1])+(res(i,k-1,a,dp))+(res(k+1,j,a,dp));
            minm=max(minm,x);
        }
        return dp[i][j]=minm;
    }
    int maxCoins(vector<int>& nums) {
       int z=nums.size();
       vector<int>x;
       x.push_back(1);
       for(int i=0;i<nums.size();i++){
        x.push_back(nums[i]);
       }
       x.push_back(1);
       vector<vector<int>>dp(z+2,vector<int>(z+2,-1));
       return res(1,z,x,dp);
    }
};