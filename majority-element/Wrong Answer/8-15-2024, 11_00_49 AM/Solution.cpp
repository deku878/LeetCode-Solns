// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int cu=-1;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cu=nums[i];
                cnt++;
            }
        }
        int ro=0;
        for(int i=0;i<nums.size();i++){
            if(cu==nums[i]){
                ro++;
            }
        }
        if(ro>=(nums.size())/2){
            return cu;
        }
        return -1;
    }
};