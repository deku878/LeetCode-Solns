// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp,mp1;
        for(int i=0;i<s.size();i++){
            if(mp.count(t[i])!=0){
                if(mp[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
            mp[t[i]]=s[i];}
        }
        for(int i=0;i<s.size();i++){
            if(mp1.count(s[i])!=0){
                if(mp1[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
            mp1[s[i]]=t[i];}
        }
        return true;
    }
};