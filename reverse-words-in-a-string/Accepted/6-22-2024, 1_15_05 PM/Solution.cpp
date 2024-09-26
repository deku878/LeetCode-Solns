// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int idx=0;
        int lidx=s.size()-1;
        while(s[idx]==' '){
            idx++;
        }
        while(s[lidx]==' '){
            lidx--;
        }
        vector<string>x;
        string y="";
        for(int i=idx;i<=lidx;i++){
            if(s[i]==' '){
                if(y.size()!=0){
                x.push_back(y);
                y="";}
            }
            else{
                y+=s[i];
            }
        }
        x.push_back(y);
        reverse(x.begin(),x.end());
        string u="";
        string p=" ";
        for(int i=0;i<x.size();i++){
            if(i!=x.size()-1){
                u+=x[i];
                u+=p;
            }
            else{
                u+=x[i];
            }
        }
        return u;
    }
};