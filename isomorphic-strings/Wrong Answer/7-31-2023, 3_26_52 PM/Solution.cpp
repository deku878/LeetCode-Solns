// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool check=true;
        map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() and mp[s[i]]!=t[i]){
                check=false;
            }
            else{
                mp[s[i]]=t[i];
            }
        }
        return check;
    }
};