// https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
public:
    int minSideJumps(vector<int>& o) {
        long long int n=o.size();
        vector<int>dp1(n,n),dp2(n,n),dp3(n,n);
        dp1[0]=1,dp2[0]=0,dp3[0]=1;
        for(int i=1;i<n;i++){
            if(o[i-1]!=1 and o[i]!=1){
                dp1[i]=dp1[i-1];
            }
            if(o[i-1]!=2 and o[i]!=2){
                dp2[i]=dp2[i-1];
            }
            if(o[i-1]!=3 and o[i]!=3){
                dp3[i]=dp3[i-1];
            }
            dp1[i]=min({dp1[i],1+dp2[i],1+dp3[i]});
            dp2[i]=min({dp2[i],1+dp1[i],1+dp3[i]});
            dp3[i]=min({dp3[i],1+dp2[i],1+dp1[i]});
        }
        return min({dp1[n-1],dp2[n-1],dp3[n-1]});
    }
};