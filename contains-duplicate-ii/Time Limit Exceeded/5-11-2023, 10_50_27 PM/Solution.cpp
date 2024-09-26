// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size();++j){
                if(((nums[i]==nums[j]) and (abs(i-j)<=k))and (i!=j) ){
                    count++;
                }
            }
        }
        if(count!=0){
            return true;
        }
        else{
            return false;
        }
    }
};