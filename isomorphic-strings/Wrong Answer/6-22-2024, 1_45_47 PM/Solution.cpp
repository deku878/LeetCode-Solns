// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
            mp[s[i]]=t[i];}
            else if(mp[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};