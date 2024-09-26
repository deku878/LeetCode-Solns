// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, long long int n) {
        long long int v=n;
        n=abs(n);
        vector<double>p(n+1);
        p[0]=1;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]*x;
        }
        if(v>=0){
        return p[n];}
        return 1/(p[n]);

    }
};