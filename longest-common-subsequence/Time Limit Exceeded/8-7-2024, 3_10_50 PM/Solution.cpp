// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string x,string y,int n,int m){
        if(n<=0 or m<=0){
            return 0;
        }
        if(x[n-1]==y[m-1]){
            return 1+lcs(x,y,n-1,m-1);
        }
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return lcs(text1,text2,n,m);
    }
};