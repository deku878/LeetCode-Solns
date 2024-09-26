// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int>o=nums;
        int n=nums.size();
        if(n<=2){
            sort(o.begin(),o.end());
            return o[o.size()-1];
        }
        for(int i=0;i<n;i++){
            o.push_back(nums[i]);
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>dp(n);
            dp[0]=nums[i];
            for(int j=1;j<n-1;j++){
                dp[j]=o[i+j];
                if(j-1>=0){
                    dp[j]=max(dp[j-1],dp[j]);
                }
                if(j-2>=0){
                    dp[j]=max(dp[j-2]+o[j+i],dp[j]);
                }
            }
            maxm=max(maxm,dp[n-2]);
        }
        return maxm;
    }
};