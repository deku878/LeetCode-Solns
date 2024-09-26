// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>d(nums.size());
        d=nums;
        if(nums.size()>=k){
        for(int i=0;i<nums.size();i++){
            int p=(i+k);
            if(p>nums.size()-1){
                int c=p-nums.size();
                nums[c]=d[i];
            }
            else{
                nums[i+k]=d[i];
            }
        }}
        else{
            reverse(nums.begin(),nums.end());
        }
        }
};