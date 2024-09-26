// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        //base case:
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                long long int maxm=INT_MIN;
                for(int k=i;k<=j;k++){
                    //i to j segment
                    //k break mara beech me
                    //i se k-1 ka segment
                    //k+1 se j ka segment baki saare burst
                    long long int leftkasmax=dp[i][k-1];
                    long long int rightkamx=dp[k+1][j];
                    //k ranges from i-n
                    //i ki value is fixed ek i ke lie calc horha hh
                    long long int c=nums[i-1]*nums[k]*nums[j+1];
                    c+=leftkasmax;
                    c+=rightkamx;
                    maxm=max(c,maxm);
                }
                dp[i][j]=maxm;
            }
        }
        return dp[1][n];
    }
};