// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(!st.empty() and s[st.top()]=='('){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        int res=s.size();
        int re=0;
        while(!st.empty()){
            int now=st.top();
            re=max(re,res-now-1);
            res=now;
            st.pop();
        }
        return max(re,res);
    }
};