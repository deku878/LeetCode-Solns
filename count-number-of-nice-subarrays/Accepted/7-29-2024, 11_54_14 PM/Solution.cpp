// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int atmost(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        int odd=0;
        int j=0;
        int ro=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd++;
            }
            while(odd>k){
                if(nums[j]%2!=0){
                    odd--;
                }
                j++;
            }
            ro+=i-j+1;
        }
        return ro;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};