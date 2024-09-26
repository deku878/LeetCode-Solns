// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int lcs(string s,string t,int n,int m){
        if(n==0 or m==0){
            return 0;
        }
        if(s[n-1]==t[m-1]){
            return 1+lcs(s,t,n-1,m-1);
        }
        return max(lcs(s,t,n-1,m),lcs(s,t,n,m-1));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        int m=t.size();
        return lcs(s,t,n,m);
    }
};