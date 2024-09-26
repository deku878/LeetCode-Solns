// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int res(int i,int j,vector<int>&dp,string&a){
    if(i==a.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    long long int mini=INT_MAX;
    for(int k=i;k<j;k++){
        if(isPalindrome(i,k,a)){
            long long int t=1+res(k+1,a.size(),dp,a);
            mini=min(mini,t);
        }
    }
    return dp[i]=mini;
}
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        int n=s.size();
        return res(0,n,dp,s)-1;
    }
};
