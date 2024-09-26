// https://leetcode.com/problems/largest-sum-of-averages

class Solution {
public:
    vector<vector<double>>dp;
    double helper(vector<int>& a,int idx,int k)
    {
        if(idx >= a.size()) return 0;
        if(!k) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        double ans = INT_MIN;
        double sum = 0;
        for(int i = idx;i<a.size();i++)
        {
            sum = sum+a[i];
            ans = max(sum/(i-idx+1) + helper(a,i+1,k-1),ans);
        }
        return dp[idx][k] = ans;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        dp=vector<vector<double>>(n,vector<double>(K+1,-1));
        return helper(A,0,K);      
    }
};