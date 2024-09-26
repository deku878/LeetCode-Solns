// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool checker(vector<int>&nums,int k,int mid){
        long long int sum=0;
        long long int res=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                res++;
                sum=nums[i];
            }
            if(res>k){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long int lo=1;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long int hi=sum;
        long long int ans=sum;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(checker(nums,k,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};