// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
       int t[501];
    int solve(vector<int>& ip,int ind,int n,int k){
        if(ind>=n) return 0; 

        if(t[ind]!=-1) return t[ind];

        int ans=INT_MIN;
        int maxi=INT_MIN;

        // jis index pe hai vnha se k size tak ka check kr rhe 
        // you may think that why min ?
        // think about the case that, you have not k element then the group must be less than k na, isiliye ki out of bound na ho jaye.
        for(int i=ind;i<min(ind+k,n);i++){
            maxi=max(ip[i],maxi);
            // partition kar rhe and us range ka maximum nikal rhe
            ans=max(ans,solve(ip,i+1,n,k) +(i-ind+1)*maxi);
        }

        return t[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,0,n,k);
    }
};