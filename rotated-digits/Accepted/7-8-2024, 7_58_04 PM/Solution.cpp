// https://leetcode.com/problems/rotated-digits

class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int p=i;
            string x=to_string(p);
            string y=x;
            dp[i]=dp[i-1];
            bool check=true;
            for(int j=0;j<x.size();j++){
                if(x[j]=='2'){
                    x[j]='5';
                }
                else if(x[j]=='5'){
                    x[j]='2';
                }
                else if(x[j]=='6'){
                    x[j]='9';
                }
                else if(x[j]=='9'){
                    x[j]='6';
                }
                else if(x[j]=='3' or x[j]=='4' or x[j]=='6' or x[j]=='7'){
                    check=false;
                    
                }
            }
            if(y!=x and check){
                dp[i]+=1;
            }
        }
        return dp[n];
    }
};