// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        map<int,int>mp;
        int maxf=INT_MIN;
        int maxlen=0;
        while(j<s.size()){
            mp[s[j]]++;
            maxf=max(maxf,mp[s[j]]);
            while(j-i+1-maxf>k){
                mp[s[i]]--;
                if(mp[s[i]]<=0){
                    mp.erase(s[i]);
                }
                for(char c='a';c<='z';c++){
                    maxf=max(maxf,mp[c]);
                }
                i++;
            }
            if(j-i+1-maxf<=k){
                maxlen=j-i+1;
            }
            j++;
        }
        return maxlen;
    }
};