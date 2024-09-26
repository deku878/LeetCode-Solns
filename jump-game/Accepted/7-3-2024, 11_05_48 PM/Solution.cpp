// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0;
        int curr=0;
        int jumps=1;
        for(int i=0;i<nums.size();i++){
            max_reach=max(max_reach,nums[i]+i);
            if(curr==i){
                jumps++;
                curr=max_reach;
            }
        }
        return curr>=nums.size()-1;
    }
};