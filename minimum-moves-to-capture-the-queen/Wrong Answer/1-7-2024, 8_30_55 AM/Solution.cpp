// https://leetcode.com/problems/minimum-moves-to-capture-the-queen

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int ans=0;
        if(a==e or b==f){
            ans=1;
        }
        else if(a!=e and b!=f){
            ans=2;
        }
        if(c-d==e-f or c+d==e+f){
            if(c-d!=a-b and c+d!=a+b){
            ans=min(ans,1);}
            else{
                if(a<c and b<e){
                ans=min(ans,2);}
                else{
                    ans=min(ans,1);
                }
            }
        }
        else if(c-d!=e-f and c+d!=e+f){
            ans=min(ans,2);
        }
        return ans;
    }
};