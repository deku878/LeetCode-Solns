// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int ans=0;
    void res(vector<int>&x,int target,int idx){
        if(idx>=x.size() or target<0){
            return;
        }
        else if(target==0){
            ans++;
            return;
        }
        res(x,target-x[idx],idx);
        res(x,target,idx+1);
    }
    int combinationSum4(vector<int>& nums, int target) {
        int coins=0;
        int n=nums.size();
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int j=0;j<=target;j++){
        for(int i=0;i<n;i++){
            if(j+nums[i]<=target){
                dp[j+nums[i]]+=dp[j];
            }
        }}
        return dp[target];
    }
};