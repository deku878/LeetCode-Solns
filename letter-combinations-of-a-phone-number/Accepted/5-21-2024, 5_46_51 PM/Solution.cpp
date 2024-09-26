// https://leetcode.com/problems/letter-combinations-of-a-phone-number

#include<bits/stdc++.h>
class Solution {
    map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            vector<string>p={};
            return p;
        }
        char c=digits[0];
        string p=digits.substr(1);
        vector<string>x=letterCombinations(p);
         vector<string>y;
        string h=mp[c];
        if(x.size()==0){
            for(int i=0;i<h.size();i++){
                y.push_back(h.substr(i,1));
            }
        }
        for(int i=0;i<mp[c].size();i++){
            for(auto s:x){
                y.push_back(h[i]+s);}
            }
        return y;
    }
};