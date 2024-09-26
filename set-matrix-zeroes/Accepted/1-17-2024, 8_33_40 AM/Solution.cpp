// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>vc;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                vc.push_back({i,j});}
            }
        }
        while(vc.size()){
        long long int y=vc.back().first;
        long long int z=vc.back().second;
        for(int i=0;i<matrix[0].size();i++){
           matrix[y][i]=0;
        }
        for(int j=0;j<matrix.size();j++){
            matrix[j][z]=0;
        }
        vc.pop_back();
        }
    }
};