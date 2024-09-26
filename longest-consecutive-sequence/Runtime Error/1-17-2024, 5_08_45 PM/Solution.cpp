// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        vector<bool>vis(10000,false);
        vector<int>c;
        for(int i=0;i<nums.size();i++){
            if(!vis[nums[i]]){
                c.push_back(nums[i]);
            }
        }
        sort(c.begin(),c.end());
        long long int count=1;
        long long int realcount=1;
        for(int i=0;i<c.size()-1;i++){
            if(c[i]+1==c[i+1]){
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