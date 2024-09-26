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
        //expand around center approach
        string x="";
        for(int i=0;i<s.size();i++){
            //check for odd length
            //check for even length
            int i2=i;
            int j2=i;
            while(i2>=0 and j2<s.size()){
                if(s[i2]==s[j2]){
                    string t=s.substr(i2,j2-i2+1);
                    if(t.size()>x.size()){
                        x=t;
                    }
                    i2--;
                    j2++;
                }
                else{
                    break;
                }
            }
            int i1=i;
            int j1=i+1;
            int count=0;
            while(i1>=0 and j1<s.size()){
                if(s[i1]==s[j1]){
                    string t=s.substr(i1,j1-i1+1);
                    if(t.size()>x.size()){
                        x=t;
                    }
                    i1--;
                    j1++;
                }
                else{
                    break;
                }
            }
        }
        return x;
    }
};