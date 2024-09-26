// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.length();
        vector<int>lps(len);
        lps[0]=0;
        int i=1;
        int j=0;
        while(i<len){
            if(needle[i]==needle[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    lps[i]=0;
                    i++;

                }
            }
        }
        int lenText=haystack.length();
        int lenPat=needle.length();
        i=0;
        j=0;
        while(i<lenText and j<lenPat){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[i-1];
                }
                else{
                        i++;
                    }
                }
            }
        if(j==lenPat){
            return i-lenPat;
        }
        return -1;}
};