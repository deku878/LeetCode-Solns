// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long int n=nums.size();
        map<int,int>mp;
        vector<int>c;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            if(m.second>n/3){
                c.push_back(m.first);
            }
        }
        return c;
    }
};