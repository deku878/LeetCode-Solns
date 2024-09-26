// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=nums.size();
        int ze=0;
        int j=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ze++;
            }
            while(ze>k){
                if(nums[j]==0){
                    ze--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};