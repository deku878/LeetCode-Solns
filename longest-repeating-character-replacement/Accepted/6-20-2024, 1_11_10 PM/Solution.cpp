// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0;
        int maxf=0;
        map<char,int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            if((r-l+1)-maxf>k){
                mp[s[l]]--;
                maxf=0;
                for(char c='A';c<='Z';c++){
                    maxf=max(maxf,mp[c]);
                }
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};