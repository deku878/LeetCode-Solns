// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>x;
        vector<int>y;
        y.push_back(1);
        x.push_back(y);
        for(int i=1;i<numRows;i++){
            vector<int>z(i+1,0);
            z[0]=1;
            z[i]=1;
            for(int j=1;j<i;j++){
                z[j]=x[i-1][j]+x[i-1][j-1];
            }
            x.push_back(z);
        }
        return x;
    }
};