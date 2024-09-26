// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        vector<int>c;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            if(m.second>n/2){
                c.push_back(m.first);
            }
        }
        return c[0];
    }
};