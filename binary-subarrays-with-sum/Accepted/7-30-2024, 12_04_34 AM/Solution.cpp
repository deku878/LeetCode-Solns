// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
public:
    int atmost(vector<int>&nums,int goal){
        if(goal<0){
            return 0;
        }
         map<char,int>mp;
        int j=0;
        int g=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            g+=nums[i];
            while(g>goal){
                g-=nums[j];
                j++;
            }
            cnt+=i-j+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};