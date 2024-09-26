// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int in=0;
       int jn=0;
       int prev=-1;
       int prev2=-1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            in++;
            if(prev!=i-1){
                in++;
            }
            prev=i;
        }
        else{
            jn++;
            if(prev2!=i-1){
                jn++;
            }
            prev2=i;
        }
       }
       int maxm=max(in,jn);
       return maxm;
    }
};