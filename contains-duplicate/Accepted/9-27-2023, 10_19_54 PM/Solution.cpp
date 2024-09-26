// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        bool check=false;
        for(auto m:mp){
            if(m.second>=2){
                check=true;
            }
        }
        return check;
    }
};