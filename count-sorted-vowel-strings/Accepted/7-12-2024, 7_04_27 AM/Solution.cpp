// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        int ans=0;
        for(int j=0;j<n;j++){
            ans=a+e+i+o+u;
            a=a+e+i+o+u;
            e=e+i+o+u;
            i=i+o+u;
            o=o+u;
        }
        return ans;
    }
};