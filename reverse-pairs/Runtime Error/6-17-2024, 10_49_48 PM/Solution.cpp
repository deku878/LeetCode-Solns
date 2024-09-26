// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        multiset<int>s;
        s.insert(nums[0]);
        map<int,int>mp;
        int cnt=0;
        for(int i=1;i<nums.size();i++){
                if(mp.count(nums[i])==0){
                s.insert(2*nums[i]);
                auto it=s.upper_bound(2*nums[i]);
                int z=distance(it,s.end());
                cnt+=z;
                mp[nums[i]]=z;
                s.insert(nums[i]);
                s.erase(s.find(2*nums[i]));
                }
                else{
                s.insert(2*nums[i]);
                auto it=s.upper_bound(2*nums[i]);
                int y=(i+1);
                int z=distance(it,s.end());
                cnt+=z-mp[nums[i]];
                mp[nums[i]]=z;
                s.insert(nums[i]);
                s.erase(s.find(2*nums[i]));
                }
        }
        return cnt;
    }
};