// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
      int len=0;
      for(auto curr:a){
      if(len==0 or a[len-1]<curr){
          a[len++]=curr;
      }
      else{
          *lower_bound(a.begin(),a.begin()+len,curr)=curr;
      }
      }
      return len;
    }
};