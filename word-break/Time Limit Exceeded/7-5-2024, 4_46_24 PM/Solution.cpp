// https://leetcode.com/problems/word-break

class Solution {
public:
    bool checker(int idx,vector<int>&dp,string s,vector<string>& w){
        if(idx==s.size()){
            return true;
        }
        string x="";
        bool f=false;
        for(int i=idx;i<s.size();i++){
            x+=s[i];
            if(find(w.begin(),w.end(),x)!=w.end() and checker(i+1,dp,s,w)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        return checker(0,dp,s,wordDict);
    }
};