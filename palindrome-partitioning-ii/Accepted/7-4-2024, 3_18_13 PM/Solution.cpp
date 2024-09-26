// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool ispal(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minx(int i,string &s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(ispal(s,i,s.size()-1)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispal(s,i,j)){
                mini=min(1+minx(j+1,s,dp),mini);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return minx(0,s,dp);
    }
};