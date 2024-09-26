// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    int calculate(string p) {
        int len=p.length();
        if(len==0){
            return 0;
        }
        stack<int>s;
        int currentnumber=0;
        char operation='+';
        for(int i=0;i<p.size();i++){ 
            char currentchar=p[i];
            if(isdigit(currentchar)){
                currentnumber=currentnumber*10+(currentchar-'0');
            }
            if(!isdigit(currentchar) and !iswspace(currentchar) or i==len-1){
                if(operation=='+'){
                    s.push(currentnumber);
                }
                else if(operation=='-'){
                    s.push(currentnumber);
                }
                else if(operation=='*'){
                    int stacktop=s.top();
                    s.pop();
                    s.push(stacktop*currentnumber);
                }
                else if(operation=='/'){
                    int stacktop=s.top();
                    s.pop();
                    s.push(stacktop/currentnumber);
                }
                operation=currentchar;
                currentnumber=0;
            }
        }
        int result=0;
        while(s.size()!=0){
            result+=s.top();
            s.pop();
        }
        return result;
    }
};