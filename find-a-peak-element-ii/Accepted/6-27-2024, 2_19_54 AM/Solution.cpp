// https://leetcode.com/problems/find-a-peak-element-ii

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int row=0, col=m-1, x;
        while(row<n && col>=0){
            x = matrix[row][col];
            if(row>0 && matrix[row-1][col]>matrix[row][col]) row--;
            if(row<n-1 && matrix[row+1][col]>matrix[row][col]) row++;
            if(col>0 && matrix[row][col-1]>matrix[row][col]) col--;
            if(col<m-1 && matrix[row][col+1]>matrix[row][col]) col++;

            if(x==matrix[row][col]) return {row, col};
        }
        return {-1,-1};
    }
};