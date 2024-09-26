// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string s) {
        //north-positive
        //south-negative
        //east-positive
        //west-negative
        int dirx=0,diry=1;
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='G'){
                x+=dirx;
                y+=diry;
            }
            else if(s[i]=='L'){
                int  p=0;
                p=dirx;
                dirx=-1*diry;
                diry=p;
            }
            else if(s[i]=='R'){
                int lp=0;
                lp=dirx;
                dirx=diry;
                diry=lp;
            }
        }
        if((x==0 and y==0) or (dirx!=0 or diry!=1)){
            return true;
        }
        return false;
    }
};