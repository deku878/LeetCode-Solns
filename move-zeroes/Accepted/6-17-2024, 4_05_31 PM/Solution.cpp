// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        vector<int>x;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
            x.push_back(nums[i]);}
            else{cnt++;}
        }
        while(cnt--){
            x.push_back(0);
        }
        nums=x;
    }
};