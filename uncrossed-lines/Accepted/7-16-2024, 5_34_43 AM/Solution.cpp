// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int helper(int i,int j,vector<int>&a,vector<int>&b,vector<vector<int>>&dp){
        if(i<0 or j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int notak=max(helper(i-1,j,a,b,dp),helper(i,j-1,a,b,dp));
        int tak=-1;
        if(a[i]==b[j]){
            tak=1+helper(i-1,j-1,a,b,dp);
        }
        return dp[i][j]=max(notak,tak);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(n1-1,n2-1,nums1,nums2,dp);
    }
};