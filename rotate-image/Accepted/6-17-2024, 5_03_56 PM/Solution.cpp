// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        map<pair<int,int>,int>mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(mp.count({i,j})==0 and mp.count({j,i})==0){
                swap(matrix[i][j],matrix[j][i]);
                mp[{i,j}]=1;
                mp[{j,i}]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            vector<int>x=matrix[i];
            reverse(x.begin(),x.end());
            matrix[i]=x;
        }

    }
};