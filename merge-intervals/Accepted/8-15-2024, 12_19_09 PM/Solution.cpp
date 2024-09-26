// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>start={intervals[0][0],intervals[0][1]};
        vector<vector<int>>res;
        for(int i=1;i<intervals.size();i++){
            if(start[1]>=intervals[i][0]){
                start[1]=max(start[1],intervals[i][1]);
            }
            else{
                res.push_back(start);
                start={intervals[i][0],intervals[i][1]};
            }
        }
        res.push_back(start);
        return res;
    }
};