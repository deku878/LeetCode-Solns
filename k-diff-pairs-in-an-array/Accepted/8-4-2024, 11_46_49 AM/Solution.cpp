// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto m:mp){
            cout<<m.first<<" "<<m.second<<endl;
        }
        for(auto m:mp){
            if(k==0){
               if(m.second>1){
               cnt+=1; }
            }
            else{
              if(mp.count(m.first-k)!=0){
               cnt+=1;}
            }
        }
        return cnt;
    }
};