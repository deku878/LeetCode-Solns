// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int maxm=INT_MIN;
        int minm=INT_MAX;
        int idx=-1;
        vector<int>res;
        res=nums;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minm){
                idx=i;
                break;
            }
        }
        int cnt=0;
        while(cnt<nums.size()-1){
            if(nums[idx%nums.size()]>nums[(idx+1)%nums.size()]){
                return false;
            }
            cnt++;
        }
        return true;
    }
};