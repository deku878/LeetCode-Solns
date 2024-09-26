// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=INT_MIN;
        for(int i=0;i<dimensions.size();i++){
            int p=pow(dimensions[i][0],2)+pow(dimensions[i][1],2);
            if(sqrt(p)>ans){
                ans=sqrt(p);
            }
        }
        return ans;
    }
};