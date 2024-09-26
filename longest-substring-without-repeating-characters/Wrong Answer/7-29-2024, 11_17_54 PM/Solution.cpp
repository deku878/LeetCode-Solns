// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>mp;
        int maxm=INT_MIN;
        int prev=-1;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                maxm=max(maxm,i-prev);
                mp[s[i]]=i;
            }
            else{
                prev=mp[s[i]];
                mp[s[i]]=i;
            }
        }
        if(maxm==INT_MIN){
            return 0;
        }
        return maxm;
    }
};