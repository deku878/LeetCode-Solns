// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    map<int,string>mp{{0,"0"},{1,"1"},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void solve(map<int,string>&mp,string digits,string &res,int idx,vector<string>&y){
        if(idx==digits.size()){
            y.push_back(res);
            return;
        }
        int nums=digits[idx]-'0';
        for(int i=0;i<mp[nums].size();i++){
            res.push_back(mp[nums][i]);
            solve(mp,digits,res,idx+1,y);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>yu;
        if(digits.size()==0){
            return yu;
        }
        string p="";
        solve(mp,digits,p,0,yu);
        return yu;
    }
};