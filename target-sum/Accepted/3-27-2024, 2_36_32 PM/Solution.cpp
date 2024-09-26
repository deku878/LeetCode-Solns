// https://leetcode.com/problems/target-sum

class Solution {
public:
int helper(vector<int> &arr,int n,int t){
   int dp[n+1][t+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<t+1;j++){
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=0;j<t+1;j++){
            if(arr[i-1]<=j) dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][t];
}
    int findTargetSumWays(vector<int>& nums, int d) {
        int n= nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);

       int t = ((sum+d)/2);
       if(d>sum || (d+sum)%2 !=0  || t<0)
       return 0;
       
       return helper(nums,n,t);
    }
};