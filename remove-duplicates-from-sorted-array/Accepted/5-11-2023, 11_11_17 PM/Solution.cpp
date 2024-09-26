// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]++];
        }
        nums.clear();
        for(auto m:mp){
            nums.push_back(m.first);
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return n;
    }
};