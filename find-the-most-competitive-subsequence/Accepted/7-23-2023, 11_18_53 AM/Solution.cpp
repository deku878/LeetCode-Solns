// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;++i){
            while(!ans.empty() and nums[i]<ans.back() and k-(int)ans.size()<=n-i-1){
                ans.pop_back();
            }
            if(ans.size()<k){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};