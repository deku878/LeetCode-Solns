// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zeroes=0;
        int j=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[j]==0){
                    zeroes--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};