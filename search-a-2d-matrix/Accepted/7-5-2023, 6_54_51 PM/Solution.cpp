// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = m - 1;
    
    while (start >= 0 && start < n && end >= 0 && end < m) {
        if (matrix[start][end] > target) {
            end--;
        } else if (matrix[start][end] < target) {
            start++;
        } else if (matrix[start][end] == target) {
            return true;
        }
    }
    
    return false;
}
};