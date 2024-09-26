// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool isP(string&s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
    void backtrack(string &s,int idx,vector<string>curr,vector<vector<string>>&result){
        if(idx==s.size()){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isP(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>curr;
        vector<string>x;
        backtrack(s,0,x,curr);
        return curr;
    }
};