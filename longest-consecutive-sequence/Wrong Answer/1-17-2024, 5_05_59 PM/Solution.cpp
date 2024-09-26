// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        long long int count=1;
        long long int realcount=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1==nums[i+1]){
                count++;
            }
            else{
                realcount=max(realcount,count);
                count=1;
            }
        }
        if(count>1){
            realcount=max(realcount,count);
        }
        return realcount;
    }
};