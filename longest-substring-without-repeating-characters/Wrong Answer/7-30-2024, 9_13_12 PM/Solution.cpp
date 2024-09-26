// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int prev=-1;
        int sz=1;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])!=0){
            prev=max(prev,mp[s[i]]);}

            mp[s[i]]=i;

            sz=max(sz,i-prev);
        }
        return sz;
    }
};