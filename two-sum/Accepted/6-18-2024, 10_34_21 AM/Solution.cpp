// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        vector<pair<int,int>>nums1(nums.size());
        for(int i=0;i<nums.size();i++){
            nums1[i].first=nums[i];
            nums1[i].second=i;
        }
        sort(nums1.begin(),nums1.end());
        vector<int>x;
        while(lo<hi){
            if(nums1[lo].first+nums1[hi].first==target){
                x.push_back(nums1[lo].second);
                x.push_back(nums1[hi].second);
                return x;
            }
            else if(nums1[lo].first+nums1[hi].first>target){
                hi--;
            }
            else{
                lo++;
            }
        }
        return x;
    }
};