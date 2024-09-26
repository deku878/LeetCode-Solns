// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    long long int res(vector<int>&nums,int k){
        int j=0;
        int p=nums.size();
        int i=0;
        long long int count=0;
        int rc=0;
        while(j<p){
            if(nums[j]%2!=0){
            rc++;}
            while(rc>k){
                if(nums[i]%2!=0){
                rc--;}
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    long long int numberOfSubarrays(vector<int>& nums, int k) {
       return res(nums,k)-res(nums,k-1);
    }
};