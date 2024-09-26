// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        string h="";
        map<char,int>mp;
        bool flag=false;
        bool neg=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='10' or s[i]=='0'  or s[i]=='1'  or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7'  or s[i]=='8' or s[i]=='9'){
            h+=s[i];
            flag==true;
            }
            if(s[i]=='-'){
            mp['-']++;}
            if(flag==false){
                if(mp.count('-')!=0){
                    neg=true;
                }
            }
        }
        long long int p=0;
        reverse(h.begin(),h.end());
        for(int i=0;i<h.size();i++){
            p+=(h[i]-'0')*(pow(10,i));
        }
        if(neg){
            p*=-1;
        }
        return p;
    }
};