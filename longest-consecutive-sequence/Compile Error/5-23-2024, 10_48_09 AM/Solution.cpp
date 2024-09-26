// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        if(n==1){
            if(a[0]==0){
            return 1;}
            return 0;
        }
        else if(n==0){
            return 0;
        }
        unordered_set<int>p;
        for(int i=0;i<nums.size();i++){
            p.insert(nums[i]);
        }
        for(auto it:p){
            if(p.find(it-1)==p.end()){
                int c=1;
                int x=it;
                while(p.find(x+1)!=p.end()){
                    x++;
                    c++;
                }
                longest=max(c,longest);
            }
        }
        return longest;
    }
};