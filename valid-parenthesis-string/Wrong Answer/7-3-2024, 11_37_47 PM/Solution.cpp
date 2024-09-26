// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        int cnt=0;
        if((count(s.begin(),s.end(),'(')==s.size())){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                cnt++;
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty() and cnt<1){
                    return false;
                }
                else if(!st.empty()){
                    st.pop();
                }
            }
        }
        return true;
    }
};