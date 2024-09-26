// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        //2d integers
        //width and height are larger
        vector<vector<int>>p;
        for(int i=0;i<e.size();i++){
            vector<int>c=e[i];
            if(find(p.begin(),p.end(),c)==p.end()){
                p.push_back(c);
            }
        }
        sort(p.begin(),p.end());
        int n=p.size();
        vector<int>dp(p.size(),1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(p[i][0]>p[j][0] and p[i][1]>p[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp[dp.size()-1];
    }
};