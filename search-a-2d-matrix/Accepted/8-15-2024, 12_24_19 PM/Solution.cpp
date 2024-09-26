// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lastc=matrix[0].size()-1;
        int lastr=0;
        while(lastc>=0 and lastr<matrix.size()){
            if(matrix[lastr][lastc]>target){
                lastc--;
            }
            else if(matrix[lastr][lastc]<target){
                lastr++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};