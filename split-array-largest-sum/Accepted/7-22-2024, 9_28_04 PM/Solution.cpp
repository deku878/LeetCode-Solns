// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool checker(vector<int>&nums,int k,int mid){
        int io=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                return false;
            }
            if(io+nums[i]<=mid){
                io+=nums[i];
                
            }
            else{
                cnt++;
                io=nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo=INT_MAX;
        for(int i=0;i<nums.size();i++){
            lo=min(lo,nums[i]);
        }
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(checker(nums,k,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
            lo=mid+1;}
        }
        return ans;
    }
};