// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int len=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                maxlen=max(maxlen,i-len+1);
            }
            else{
                while(mp.count(s[i])!=0){
                    mp[s[len]]--;
                    if(mp[s[len]]==0){
                        mp.erase(s[len]);
                    }
                    len++;
                }
            }
            mp[s[i]]++;
        }
        return maxlen;
    }
};