// https://leetcode.com/problems/minimum-moves-to-capture-the-queen

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int ans=0;
        if(a==e or b==f){
            ans=1;
        }
        if(a!=e and b!=f){
            ans=2;
        }
        if(a-b==e-f or a+b==e+f){
            ans=min(ans,1);
        }
        if(a-b!=e-f and a+b!=e+f){
            ans=min(ans,2);
        }
        return ans;
    }
};