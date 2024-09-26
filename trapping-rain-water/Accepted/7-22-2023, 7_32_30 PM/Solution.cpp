// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& a) {
      int n=a.size();
      vector<int>leftm(n);
      leftm[0]=a[0];
      int sum=0;
      for(int i=1;i<n;i++){
          leftm[i]=max(a[i],leftm[i-1]);
      }
      vector<int>rightm(n);
      rightm[n-1]=a[n-1];
      for(int i=n-2;i>=0;i--){
          rightm[i]=max(a[i],rightm[i+1]);
      }
      for(int i=0;i<n;i++){
          sum+=min(leftm[i],rightm[i])-a[i];
      }
     return sum;
    }
};