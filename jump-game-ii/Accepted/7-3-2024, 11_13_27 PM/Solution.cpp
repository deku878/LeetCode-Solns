// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int maxreach=0;
        int curr=0;
        for(int i=0;i<nums.size()-1;i++){
            maxreach=max(maxreach,nums[i]+i);
            if(curr==i){
                curr=maxreach;
                jumps++;
            }
        }
        return jumps;
    }
};