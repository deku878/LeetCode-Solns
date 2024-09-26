// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int>lis(a.size(),1);
        int ans=INT_MIN;
            for(int i=a.size()-1;i>=0;i--){
                for(int j=i+1;j<a.size();j++){
                    if(a[i]<a[j]){
                    lis[i]=max(lis[i],1+lis[j]);}          
                }
                ans=max(ans,lis[i]);
            }
            return ans;
        }
};