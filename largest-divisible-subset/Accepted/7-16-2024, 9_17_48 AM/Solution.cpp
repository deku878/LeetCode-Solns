// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n);
        
        vector<int>res={nums[0]};
        dp[0]=res;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and dp[i].size()<dp[j].size()){
                    dp[i]=dp[j];
                }
                
            }
            dp[i].push_back(nums[i]);
                if(res.size()<dp[i].size()){
                    res=dp[i];
                }
        }
        return res;
    }
};
