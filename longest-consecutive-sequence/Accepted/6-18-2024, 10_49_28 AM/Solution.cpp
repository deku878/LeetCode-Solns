// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int curr=-1;
        int ans=0;
        int len=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(*it!=curr+1){
                ans=1;

                len=max(len,ans);
            }
            else{
                ans++;
                len=max(len,ans);
            }
                            curr=*it;
        }
        return len;
    }
};