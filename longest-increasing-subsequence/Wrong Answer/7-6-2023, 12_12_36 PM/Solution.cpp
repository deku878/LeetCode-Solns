// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int p;
        int c=INT_MIN;
       if(count(nums.begin(),nums.end(),nums[0])==nums.size()){
           return 1;
       }
       else{
           int low=0;
           int high=nums.size()-1;
           while(low<=high){
               int max1=nums[low];
               int count1=1;
           for(int i=low+1;i<=high;i++){
               if(nums[i]>max1 and count(nums.begin(),nums.end(),nums[i])==1){
                   max1=nums[i];
                   count1++;
               }
               else if(nums[i]>max1 and count(nums.begin(),nums.end(),nums[i])>1){
                   nums[i]=-1;
               }
                p=count1;
               }
              c=max(p,c);
               low++;
           }
       }
       return c;
    }
};