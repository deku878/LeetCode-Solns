// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int in=0;
       int jn=0;
       int prev=-1;
       int prev2=-1;
       //eoeo
       //oeo
       int hn=0;
       int pn=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            in++;
                if(prev!=i-1){
                    pn+=2;
                }
             prev=i;
        }
        else{
            jn++;
          
                if(prev2!=i-1){
                    hn+=2;
                }
            prev2=i;
        }
       }
       int maxm=max({hn,pn,jn,in});
       return maxm;
    }
};