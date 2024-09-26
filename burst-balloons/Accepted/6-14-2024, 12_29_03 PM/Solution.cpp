// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int res(int i,int j,vector<int>&n,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long int x=INT_MIN;
        for(int k=i;k<=j;k++){
            long long int p=0;
            p=n[i-1]*n[k]*n[j+1];
            p+=res(i,k-1,n,dp);
            p+=res(k+1,j,n,dp);
            x=max(x,p);
        }
        return dp[i][j]=x;
    }
    int maxCoins(vector<int>& nums) {
        int o=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return res(1,o,nums,dp);
    }
};