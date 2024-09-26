// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>p;
        stack<int>x;
        x.push(-1);
        int maxlength=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                p.push(s[i]);
                x.push(i);
            }
            else{
                if(!p.empty()){
                    p.pop();
                    x.pop();
                    int maxm=i-x.top();
                    maxlength=max(maxm,maxlength);
                }
                else{
                    x.push(i);
                }
            }
        }
        return maxlength;
    }
};