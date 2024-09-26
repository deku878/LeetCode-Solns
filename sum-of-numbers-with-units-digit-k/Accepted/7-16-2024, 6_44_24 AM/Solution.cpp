// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k

class Solution {
public:
    int minimumNumbers(int nums, int k) {
        vector<int>dp(nums+1,INT_MAX);
        vector<int>res;
        for(int i=0;i<=nums;i++){
            if(i%10==k){
                res.push_back(i);
            }
        }
        dp[0]=0;
        for(int i=1;i<=res.size();i++){
            for(int j=0;j<=nums;j++){
                if(j-res[i-1]>=0 and dp[j-res[i-1]]!=INT_MAX){
                    dp[j]=min(dp[j],dp[j-res[i-1]]+1);
                }
            }
        }
        if(dp[nums]==INT_MAX){
            return -1;
        }
        return dp[nums];
    }
};