// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    long long int reversePairs(vector<int>& nums) {
        multiset<long long int>s;
        s.insert(nums[0]);
        map<long long int,long long int>mp;
        long long int cnt=0;
        for(int i=1;i<nums.size();i++){
                if(mp.count(nums[i])==0){
                long long int x=nums[i];
                long long int h1=2ll*x;
                s.insert(h1);
                auto it=s.upper_bound(h1);
                int z=distance(it,s.end());
                cnt+=z;
                mp[nums[i]]=z;
                s.insert(nums[i]);
                s.erase(s.find(h1));
                }
                else{
                long long int x=nums[i];
                long long int h1=2ll*x;
                s.insert(h1);
                auto it=s.upper_bound(h1);
                int z=distance(it,s.end());
                cnt+=z-mp[nums[i]];
                mp[nums[i]]=z;
                s.insert(nums[i]);
                s.erase(s.find(h1));
                }
        }
        return cnt;
    }
};