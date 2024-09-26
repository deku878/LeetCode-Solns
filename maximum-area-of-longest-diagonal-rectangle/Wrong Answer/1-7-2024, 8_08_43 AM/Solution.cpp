// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=INT_MIN;
        int x=INT_MIN;
        for(int i=0;i<dimensions.size();i++){
            double p=pow(dimensions[i][0],2)+pow(dimensions[i][1],2);
            if(x<p){
                x=p;
            }
            if(x>ans){
                ans=dimensions[i][0]*dimensions[i][1];
            }
        }
        return ans;
    }
};