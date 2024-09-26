// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
       int t[501];
    int solve(vector<int>& ip,int ind,int n,int k){
        if(ind>=n){
            return 0;
        }
        if(t[ind]!=-1){
            return t[ind];
        }
        int ans=INT_MIN;
        int ans1=INT_MIN;
        for(int i=ind;i<min(ind+k,n);i++){
            ans=max(ip[i],ans);
            ans1=max(ans1,(i-ind+1)*(ans)+solve(ip,i+1,n,k));
        }
        return t[ind]=ans1;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,0,n,k);
    }
};