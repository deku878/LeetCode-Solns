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
        set<string>x;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string x1=s.substr(i,j-i+1);
                x.insert(x1);
            }
        }
        string jedi="";
        for(auto it=x.begin();it!=x.end();it++){
            if(ispal(*it)){
                if(jedi.size()<(*it).size()){
                    jedi=(*it);
                }
            }
        }
        return jedi;
    }
};