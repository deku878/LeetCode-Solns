// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        vector<int>x;
        //left se right jaane ka
        map<pair<int,int>,int>mp;
        while(left<=right or top<=bottom){
        for(int i=left;i<=right;i++){
            if(mp.count({top,i})==0){
            x.push_back(matrix[top][i]);
            mp[{top,i}]++;
            }
            else{
                break;
            }
        }
        top++;
        for(int i=top;i<=bottom;i++){
           if(mp.count({i,right})==0){
            x.push_back(matrix[i][right]);
            mp[{i,right}]++;
            }
            else{
                break;
            }
        }
        right--;
        for(int i=right;i>=left;i--){
            if(mp.count({bottom,i})==0){
            x.push_back(matrix[bottom][i]);
            mp[{bottom,i}]++;
            }
            else{
                break;
            }
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            if(mp.count({i,left})==0){
            x.push_back(matrix[i][left]);
            mp[{i,left}]++;
            }
            else{
                break;
            }
        }
        left++;
        }
        return x;
    }
};