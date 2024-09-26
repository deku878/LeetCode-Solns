// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void res(int n,int cnt,string &re,vector<string>&p){
        if(re.size()==2*n){
            if(cnt!=0){
                return;
            }
            p.push_back(re);
            return;
        }
        if(cnt<0){
            return;
        }
        re.push_back('(');
        res(n,cnt+1,re,p);
        re.pop_back();
        re.push_back(')');
        res(n,cnt-1,re,p);
        re.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>real;
        string yu="";
        res(n,0,yu,real);
        return real;
    }
};