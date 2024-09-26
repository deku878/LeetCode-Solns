// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool ispal(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void helper(string s,vector<vector<string>>&dpkimkc,int idx,vector<string>&row){
        if(idx==s.size()){
            dpkimkc.push_back(row);
            return;
        }
        string p="";
        for(int i=idx;i<s.size();i++){
            p+=s[i];
            if(ispal(p)){
                row.push_back(p);
                helper(s,dpkimkc,i+1,row);
                row.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>op;
        vector<string>kl;
        helper(s,op,0,kl);
        return op;
    }
};