// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string>c;
        string p="";
        for(int i=0;i<s.size();i++){    
            if(s[i]!=' '){
                p+=s[i];
            }
            else{
                if(p.size()!=0){
                c.push_back(p);}
                p="";
            }
        }
        if(p.size()!=0){
            c.push_back(p);
        }
        reverse(c.begin(),c.end());
        string b="";
        for(int i=0;i<c.size()-1;i++){
            b+=c[i];
            b+=" ";
        }
        b+=c[c.size()-1];
        return b;
    }
};