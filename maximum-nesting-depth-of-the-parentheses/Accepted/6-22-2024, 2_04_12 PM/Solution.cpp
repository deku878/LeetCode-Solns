// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxm=INT_MIN;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                cnt++;
            }
            else if(s[i]=='('){
                cnt--;
            }
            maxm=max(maxm,cnt);
        }
        return maxm;
    }
};