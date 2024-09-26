// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>mattrans(n,vector<int>(m));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mattrans[j][i]=matrix[i][j];
            }
        }
        for(int i=0;i<m;i++){
            vector<int>temp=mattrans[i];
            reverse(temp.begin(),temp.end());
            mattrans[i]=temp;
        }
        matrix=mattrans;
    }
};