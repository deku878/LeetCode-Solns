// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
bool isp(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int res(int i,int j,vector<int>&dp,string s){
    if(i==s.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int maxm=INT_MAX;
    for(int k=i;k<=j;k++){
        if(isp(i,k,s)){
            maxm=min(maxm,1+res(k+1,s.size()-1,dp,s));
        }
    }
    return dp[i]=maxm;
}
int minCut(string s) {
        vector<int>dp(s.size(),-1);
        int n=s.size()-1;
        return res(0,n,dp,s)-1;
}
};
