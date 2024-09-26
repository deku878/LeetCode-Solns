// https://leetcode.com/problems/minimum-score-by-changing-two-elements

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        //1 4 7 8 5
       sort(nums.begin(),nums.end());
        int n=nums.size();
        return min({nums[n-1]-nums[2],nums[n-3]-nums[0],nums[n-2]-nums[1]});


    }
};