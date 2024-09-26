// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    bool ispal(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        vector<string>x;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string x1=s.substr(i,j-i+1);
                x.push_back(x1);
            }
        }
        string jedi="";
        for(int i=0;i<x.size();i++){
            if(ispal(x[i])){
                if(jedi.size()<x[i].size()){
                    jedi=x[i];
                }
            }
        }
        return jedi;
    }
};