// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        long long int count1=0;
        long long int rcount=INT_MIN;
         map<char,long long int>mp;
         if(s.size()==0){
             rcount=0;
         }
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                mp[s[i]]=i;
            }
            else{
                count1=i-mp[s[i]];
                rcount=max(rcount,count1);
                mp[s[i]]=i;
            }
            rcount=max(rcount,count1);
        }
        return rcount;
    }
};