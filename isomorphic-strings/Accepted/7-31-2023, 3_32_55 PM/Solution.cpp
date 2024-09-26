// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool check=true;
        map<char,char>mp;
        map<char,char>mp1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() and mp[s[i]]!=t[i]){
                check=false;
            }
            else if(mp1.find(t[i])!=mp1.end() and mp1[t[i]]!=s[i]){
                check=false;
            }
            else{
                mp[s[i]]=t[i];
                mp1[t[i]]=s[i];
            }
        }
        return check;
    }
};