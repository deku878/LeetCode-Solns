// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>y;
        vector<int>x={in[0][0],in[0][1]};
        int start=x[0];
        int end=x[1];
        for(int i=1;i<in.size();i++){
            if(end>=in[i][0]){
                end=in[i][1];
            }
            else{
                vector<int>z;
                z.push_back(start);
                z.push_back(end);
                y.push_back(z);
                start=in[i][0];
                end=in[i][1];
            }
        }
        vector<int>p;
        p.push_back(start);
        p.push_back(end);
        y.push_back(p);
        return y;
    }
};