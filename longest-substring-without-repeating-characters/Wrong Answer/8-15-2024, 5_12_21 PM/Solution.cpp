// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev=0;
        int len=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])!=0){
                prev=max(prev,i);
            }
            mp[s[i]]=i;
            len=max(len,i-prev+1);
        }
        return len;
    }
};