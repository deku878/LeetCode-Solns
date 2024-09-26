// https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
public:
    int minSideJumps(vector<int>& o) {
        long long int n=arr.size();
        vector<int>dp1(n,n),dp2(n,n),dp3(n,n);
        dp1[0]=1,dp2[0]=0,dp3[0]=1;
        for(int i=1;i<n;i++){
            if(o[i-1]!=1 and o[i]!=1){
                dp1[i]=dp1[i-1];
            }
            if(o[i-1]!=1 and o[i]!=1){
                dp2[i]=dp2[i-1];
            }
            if(o[i-1]!=1 and o[i]!=1){
                dp3[i]=dp3[i-1];
            }
            dp1[i]=min({dp1[i],1+dp2[i],1+dp3[i]});
            dp1[i]=min({dp1[i],1+dp2[i],1+dp3[i]});
        }
    }
};