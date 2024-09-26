// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int prev=-1;
        map<char,int>mp;
        int maxm=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])!=0){
                prev=max(mp[s[i]],prev);
            }
            mp[s[i]]=i;
            maxm=max(maxm,i-prev);
        }
        return maxm;
    }
};