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
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; // Base case: there is one way to make sum 0 (using no numbers)

        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j + nums[i] <= target) {
                    dp[j + nums[i]] += dp[j];
                }
            }
        }

        return dp[target];
    }
};