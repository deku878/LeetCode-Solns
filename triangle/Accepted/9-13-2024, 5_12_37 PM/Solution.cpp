// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res=triangle[0][0];
        vector<vector<long long int>>dp;
        for(int i=0;i<triangle.size();i++){
            vector<long long int>lol;
            for(int j=0;j<triangle[i].size();j++){
                lol.push_back(INT_MAX);
            }
            dp.push_back(lol);
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                int temp=triangle[i][j];
                if(j!=0){
                dp[i][j]=temp+dp[i-1][j-1];}
                if(j!=triangle[i].size()-1){
                dp[i][j]=min(dp[i-1][j]+triangle[i][j],dp[i][j]);} 
            }
        }
        long long int ko=INT_MAX;
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            ko=min(ko,dp[triangle.size()-1][j]);
            cout<<triangle[triangle.size()-1][j]<<" ";
        }
        return ko;
    }
    //2
    //3 4
    //6 5 7
    //4 1 8 3
};